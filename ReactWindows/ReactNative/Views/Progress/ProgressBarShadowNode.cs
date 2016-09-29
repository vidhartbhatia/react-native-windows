using Facebook.CSSLayout;
using ReactNative.UIManager;

namespace ReactNative.Views.Progress
{
    class ProgressBarShadowNode : LayoutShadowNode
    {
        public ProgressBarShadowNode()
        {
            SetMeasureFunction(MeasureProgressBar);
        }

        private static void MeasureProgressBar(CSSNode node, float width, CSSMeasureMode widthMode, float height, CSSMeasureMode heightMode, MeasureOutput output)
        {
            output.Width = width;
            output.Height = CSSConstants.IsUndefined(height) ? 4 : height;
        }
    }
}
