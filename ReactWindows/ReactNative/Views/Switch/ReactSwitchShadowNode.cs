using Facebook.CSSLayout;
using ReactNative.UIManager;

namespace ReactNative.Views.Switch
{
    /// <summary>
    /// Shadow node class for measuring <see cref="Windows.UI.Xaml.Controls.ToggleSwitch"/> instances.
    /// </summary>
    public class ReactSwitchShadowNode : LayoutShadowNode
    {
        /// <summary>
        /// Instantiates the <see cref="ReactSwitchShadowNode"/>.
        /// </summary>
        public ReactSwitchShadowNode()
        {
            SetMeasureFunction(MeasureSwitch);
        }

        private static void MeasureSwitch(CSSNode node, float width, CSSMeasureMode widthMode, float height, CSSMeasureMode heightMode, MeasureOutput output)
        {
            // TODO: figure out how to properly measure the switch.
            // We are currently blocked until we switch to a UWP-specific React
            // JavaScript library as the iOS library we currently use specifies
            // an exact width and height for switch nodes.
            output.Width = 56;
            output.Height = 40;
        }
    }
}
