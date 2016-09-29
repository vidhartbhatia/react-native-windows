using Facebook.CSSLayout;

namespace ReactNative.UIManager
{
    static class CSSNodeExtensions
    {
        public static float GetLeftBorderWidth(this CSSNode node)
        {
            var width = node.GetBorder().Get(Spacing.Left);
            if (!CSSConstants.IsUndefined(width))
            {
                return width;
            }

            width = node.GetBorder().Get(Spacing.Horizontal);
            if (!CSSConstants.IsUndefined(width))
            {
                return width;
            }

            width = node.GetBorder().Get(Spacing.All);
            if (!CSSConstants.IsUndefined(width))
            {
                return width;
            }

            return 0.0f;
        }

        public static float GetPaddingValue(this CSSNode node, CSSEdge spacingType)
        {
            var padding = node.GetPadding().Get((int)spacingType);
            if (!CSSConstants.IsUndefined(padding))
            {
                return padding;
            }

            if (spacingType == CSSEdge.Left || spacingType == CSSEdge.Right)
            {
                padding = node.GetPadding().Get(Spacing.Horizontal);
            }

            if (!CSSConstants.IsUndefined(padding))
            {
                return padding;
            }

            if (spacingType == CSSEdge.Top || spacingType == CSSEdge.Bottom)
            {
                padding = node.GetPadding().Get(Spacing.Vertical);
            }

            if (!CSSConstants.IsUndefined(padding))
            {
                return padding;
            }

            return node.GetPadding().Get(Spacing.All);
        }

        public static float GetPaddingSpace(this CSSNode node, CSSEdge spacingType)
        {
            var padding = node.GetPaddingValue(spacingType);
            return CSSConstants.IsUndefined(padding)
                ? 0.0f
                : padding;
        }

        public static float GetTopBorderWidth(this CSSNode node)
        {
            var width = node.GetBorder().Get(Spacing.Top);
            if (!CSSConstants.IsUndefined(width))
            {
                return width;
            }

            width = node.GetBorder().Get(Spacing.Vertical);
            if (!CSSConstants.IsUndefined(width))
            {
                return width;
            }

            width = node.GetBorder().Get(Spacing.All);
            if (!CSSConstants.IsUndefined(width))
            {
                return width;
            }

            return 0.0f;
        }
    }
}
