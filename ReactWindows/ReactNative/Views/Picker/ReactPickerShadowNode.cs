using Facebook.CSSLayout;
using ReactNative.UIManager;

namespace ReactNative.Views.Picker
{
    /// <summary>
    /// The shadow node implementation for Picker views.
    /// </summary>
    public class ReactPickerShadowNode : LayoutShadowNode
    {
        /// <summary>
        /// Instantiates the <see cref="ReactPickerShadowNode"/>.
        /// </summary>
        public ReactPickerShadowNode()
        {
            SetMeasureFunction(MeasurePicker);
        }

        private static void MeasurePicker(CSSNode node, float width, CSSMeasureMode widthMode, float height, CSSMeasureMode heightMode, MeasureOutput output)
        {
            output.Width = width;
            output.Height = 40;
        }
    }
}
