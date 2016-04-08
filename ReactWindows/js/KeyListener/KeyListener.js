/**
 * Copyright (c) 2015-present, Facebook, Inc.
 * All rights reserved.
 *
 * This source code is licensed under the BSD-style license found in the
 * LICENSE file in the root directory of this source tree. An additional grant
 * of patent rights can be found in the PATENTS file in the same directory.
 *
 * @providesModule KeyListener
 * @flow
 */
'use strict';

var RCTDeviceEventEmitter = require('RCTDeviceEventEmitter');

var subscriptions = [];

var KeyListener = {

  /*
   * Invokes the callback whenever an unhandled key up event occurs.
   */
  onKeyUp: function(callback: Function): number {
    var id = subscriptions.length;
    subscriptions.push([
      RCTDeviceEventEmitter.addListener(
        'keyUp',
        callback
      )
    ]);
    return id;
  },
  
  /*
   * Invokes the callback whenever an unhandled key down event occurs.
   */
  onKeyDown: function(callback: Function): number {
    var id = subscriptions.length;
    subscriptions.push(
      RCTDeviceEventEmitter.addListener(
        'keyDown',
        callback
      )
    );
    return id;
  },

  clear: function(watchID: number) {
    var sub = subscriptions[watchID];
    if (!sub) {
      // Silently exit when the watchID is invalid or already cleared
      // This is consistent with timers
      return;
    }

    sub.remove();
  }
};

module.exports = KeyListener;
