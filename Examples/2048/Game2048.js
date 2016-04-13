/**
 * The examples provided by Facebook are for non-commercial testing and
 * evaluation purposes only.
 *
 * Facebook reserves all rights not expressly granted.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
 * OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NON INFRINGEMENT. IN NO EVENT SHALL
 * FACEBOOK BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN
 * AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 *
 * @providesModule Game2048
 * @flow
 */
'use strict';

var React = require('react-native');
var {
  AppRegistry,
  Image,
  KeyListener,
  StyleSheet,
  Text,
  View,
} = React;

var Animated = require('Animated');
var GameBoard = require('GameBoard');
var TouchableBounce = require('TouchableBounce');

var BOARD_PADDING = 3;
var CELL_MARGIN = 4;
var CELL_SIZE = 60;

class Cell extends React.Component {
  render() {
    return <View style={styles.cell} />;
  }
}

class Board extends React.Component {
  render() {
    return (
      <View style={styles.board}>
        <View style={styles.row}><Cell/><Cell/><Cell/><Cell/></View>
        <View style={styles.row}><Cell/><Cell/><Cell/><Cell/></View>
        <View style={styles.row}><Cell/><Cell/><Cell/><Cell/></View>
        <View style={styles.row}><Cell/><Cell/><Cell/><Cell/></View>
        {this.props.children}
      </View>
    );
  }
}

class Tile extends React.Component {
  state: any;

  static _getPosition(index): number {
    return BOARD_PADDING + (index * (CELL_SIZE + CELL_MARGIN * 2) + CELL_MARGIN);
  }

  constructor(props: {}) {
    super(props);

    var tile = this.props.tile;

    this.state = {
      opacity: new Animated.Value(0),
      top: new Animated.Value(Tile._getPosition(tile.toRow())),
      left: new Animated.Value(Tile._getPosition(tile.toColumn())),
    };
  }

  calculateOffset(): {top: number; left: number; opacity: number} {
    var tile = this.props.tile;

    var offset = {
      top: this.state.top,
      left: this.state.left,
      opacity: this.state.opacity,
    };

    if (tile.isNew()) {
      Animated.timing(this.state.opacity, {
        duration: 100,
        toValue: 1,
      }).start();
    } else {
      Animated.parallel([
        Animated.timing(offset.top, {
          duration: 100,
          toValue: Tile._getPosition(tile.toRow()),
        }),
        Animated.timing(offset.left, {
          duration: 100,
          toValue: Tile._getPosition(tile.toColumn()),
        }),
      ]).start();
    }
    return offset;
  }

  render() {
    var tile = this.props.tile;

    var tileStyles = [
      styles.tile,
      styles['tile' + tile.value],
      this.calculateOffset(),
    ];

    var textStyles = [
      styles.value,
      tile.value > 4 && styles.whiteText,
      tile.value > 100 && styles.threeDigits,
      tile.value > 1000 && styles.fourDigits,
    ];

    return (
      <Animated.View style={tileStyles}>
        <Text style={textStyles}>{tile.value}</Text>
      </Animated.View>
    );
  }
}

class GameEndOverlay extends React.Component {
  keyListener: number;

  render() {
    var board = this.props.board;
    var isPaused = this.props.isPaused;

    KeyListener.clear(this.keyListener);

    if (!board.hasWon() && !board.hasLost() && !isPaused) {
      return <View/>;
    }
    
    this.keyListener = KeyListener.onKeyDown((keyData) =>
    {
      if (keyData.key == 'Enter' || keyData.key == 'GamepadA') {
        this.props.onRestart();
      }
    });

    var message = board.hasWon() ? 'Good Job!' 
      : board.hasLost() ? 'Game Over'
      : 'Menu';

    var text = board.hasWon() || board.hasLost() ? 'Try Again?' 
      : 'Restart';

    return (
      <View style={styles.overlay}>
        <Text style={styles.overlayMessage}>{message}</Text>
        <TouchableBounce onPress={this.props.onRestart} style={styles.tryAgain}>
          <Text style={styles.tryAgainText}>{text}</Text>
        </TouchableBounce>
      </View>
    );
  }
}

class Game2048 extends React.Component {
  startX: number;
  startY: number;
  state: any;
  keyListener: number;

  constructor(props: {}) {
    super(props);
    this.state = {
      board: new GameBoard(),
      isPaused: false,
    };
    this.startX = 0;
    this.startY = 0;
  }
  
  componentDidMount() {
    this.keyListener = KeyListener.onKeyDown((keyData) =>
    {
      if (!this.state.isPaused)
      {
        if (keyData.key == 'Left' || keyData.key == 'GamepadDPadLeft' || keyData.key == 'GamepadLeftThumbstickLeft') {
          this.setState({board: this.state.board.move(0)});
        } else if (keyData.key == 'Up' || keyData.key == 'GamepadDPadUp' || keyData.key == 'GamepadLeftThumbstickUp') {
          this.setState({board: this.state.board.move(1)});
        } else if (keyData.key == 'Right' || keyData.key == 'GamepadDPadRight' || keyData.key == 'GamepadLeftThumbstickRight') {
          this.setState({board: this.state.board.move(2)});
        } else if (keyData.key == 'Down' || keyData.key == 'GamepadDPadDown' || keyData.key == 'GamepadLeftThumbstickDown') {
          this.setState({board: this.state.board.move(3)});
        } 
      } 
      
      if (keyData.key == 'M' || keyData.key == 'GamepadMenu') {
        this.setState({isPaused: !this.state.isPaused});
      } else if (keyData.key == 'Escape' || keyData.key == 'GamepadB') {
        this.setState({isPaused: false});
      }
    });
  }
  
  componentWillUnmount() {
    KeyListener.clear(this.keyListener);      
  }

  restartGame() {
    this.setState({
      board: new GameBoard(),
      isPaused: false,
    });
  }

  handleTouchStart(event: Object) {
    if (this.state.board.hasWon() || this.state.isPaused) {
      return;
    }

    this.startX = event.nativeEvent.pageX;
    this.startY = event.nativeEvent.pageY;
  }

  handleTouchEnd(event: Object) {
    if (this.state.board.hasWon() || this.state.isPaused) {
      return;
    }

    var deltaX = event.nativeEvent.pageX - this.startX;
    var deltaY = event.nativeEvent.pageY - this.startY;

    var direction = -1;
    if (Math.abs(deltaX) > 3 * Math.abs(deltaY) && Math.abs(deltaX) > 30) {
      direction = deltaX > 0 ? 2 : 0;
    } else if (Math.abs(deltaY) > 3 * Math.abs(deltaX) && Math.abs(deltaY) > 30) {
      direction = deltaY > 0 ? 3 : 1;
    }

    if (direction !== -1) {
      this.setState({board: this.state.board.move(direction)});
    }
  }

  render() {
    var tiles = this.state.board.tiles
      .filter((tile) => tile.value)
      .map((tile) => <Tile ref={tile.id} key={tile.id} tile={tile} />);

    var overlay = null;
    if (this.state.board.hasWon() || this.state.board.hasLost() || this.state.isPaused) {
      overlay = <GameEndOverlay 
        board={this.state.board}
        isPaused={this.state.isPaused}
        onRestart={() => this.restartGame()} />
    }

    return (
      <View
        style={styles.container}>
        <Image 
          source={{uri: "http://coenraets.org/blog/wp-content/uploads/2014/12/react-logo.png"}}
          style={styles.logo} />
        <View
          onTouchStart={(event) => this.handleTouchStart(event)}
          onTouchEnd={(event) => this.handleTouchEnd(event)}>
          <Board>
            {tiles}
          </Board>
          {overlay}
        </View>
        <Image 
          source={{uri: "https://upload.wikimedia.org/wikipedia/commons/thumb/8/84/Xbox_logo_2012_cropped.svg/1036px-Xbox_logo_2012_cropped.svg.png"}} 
          style={styles.logo} />
      </View>
    );
  }
}

var styles = StyleSheet.create({
  container: {
    flex: 1,
    flexDirection: 'row',
    justifyContent: 'space-between',
    alignItems: 'center',
  },
  logo: {
    width: 250,
    height: 250,
  },
  board: {
    padding: BOARD_PADDING,
    backgroundColor: '#bbaaaa',
    borderRadius: 5,
  },
  overlay: {
    position: 'absolute',
    top: 0,
    bottom: 0,
    left: 0,
    right: 0,
    backgroundColor: 'rgba(221, 221, 221, 0.5)',
    flex: 1,
    flexDirection: 'column',
    justifyContent: 'center',
    alignItems: 'center',
  },
  overlayMessage: {
    fontSize: 40,
    marginBottom: 20,
  },
  tryAgain: {
    backgroundColor: '#887761',
    padding: 20,
    borderRadius: 5,
  },
  tryAgainText: {
    color: '#ffffff',
    fontSize: 20,
    fontWeight: '500',
  },
  cell: {
    width: CELL_SIZE,
    height: CELL_SIZE,
    borderRadius: 5,
    backgroundColor: '#ddccbb',
    margin: CELL_MARGIN,
  },
  row: {
    flexDirection: 'row',
  },
  tile: {
    position: 'absolute',
    width: CELL_SIZE,
    height: CELL_SIZE,
    backgroundColor: '#ddccbb',
    borderRadius: 5,
    flex: 1,
    justifyContent: 'center',
    alignItems: 'center',
  },
  value: {
    fontSize: 24,
    color: '#776666',
    fontFamily: 'Verdana',
    fontWeight: '500',
  },
  tile2: {
    backgroundColor: '#eeeeee',
  },
  tile4: {
    backgroundColor: '#eeeecc',
  },
  tile8: {
    backgroundColor: '#ffbb87',
  },
  tile16: {
    backgroundColor: '#ff9966',
  },
  tile32: {
    backgroundColor: '#ff7755',
  },
  tile64: {
    backgroundColor: '#ff5533',
  },
  tile128: {
    backgroundColor: '#eecc77',
  },
  tile256: {
    backgroundColor: '#eecc66',
  },
  tile512: {
    backgroundColor: '#eecc55',
  },
  tile1024: {
    backgroundColor: '#eecc33',
  },
  tile2048: {
    backgroundColor: '#eecc22',
  },
  whiteText: {
    color: '#ffffff',
  },
  threeDigits: {
    fontSize: 20,
  },
  fourDigits: {
    fontSize: 18,
  },
});

AppRegistry.registerComponent('Game2048', () => Game2048);

module.exports = Game2048;
