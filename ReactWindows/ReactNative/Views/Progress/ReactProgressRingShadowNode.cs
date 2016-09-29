using Facebook.CSSLayout;
using ReactNative.UIManager;
using Windows.UI.Xaml.Controls;

namespace ReactNative.Views.Progress
{
    /// <summary>
    /// Represents a native <see cref="ProgressRing"/> component.
    /// </summary>
    class ReactProgressRingShadowNode : LayoutShadowNode
    {
        /// <summary>
        /// Initializes an instance of a <see cref="ReactProgressRingShadowNode"/>
        /// </summary>
        public ReactProgressRingShadowNode()
        {
            SetMeasureFunction(MeasureProgressRing);
        }

        /// <summary>
        /// Measures the width and height of a <see cref="ProgressRing"/>.
        /// </summary>
        /// <param name="node">The css style of the rendered <see cref="ProgressRing"/>.</param>
        /// <param name="width">The parameterized native width of the control.</param>
        /// <param name="widthMode">The width measurement mode.</param>
        /// <param name="height">The parameterized native height of the control.</param>
        /// <param name="heightMode">The height measurement mode.</param>
        /// <param name="output">The measurement <see cref="MeasureOutput"/> for the <see cref="ProgressRing"/> component.</param>
        private static void MeasureProgressRing(CSSNode node, float width, CSSMeasureMode widthMode, float height, CSSMeasureMode heightMode, MeasureOutput output)
        {
            output.Width = !CSSConstants.IsUndefined(width) ? width : 20;
            output.Height = !CSSConstants.IsUndefined(height) ? height : 20;
        }
    }
}
