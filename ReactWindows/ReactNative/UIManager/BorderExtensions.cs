using Facebook.CSSLayout;
using Windows.UI.Xaml;
using Windows.UI.Xaml.Controls;

namespace ReactNative.UIManager
{
    static class BorderExtensions
    {
        public static void SetBorderWidth(this Border border, CSSEdge kind, double width)
        {
            var thickness = border.BorderThickness;
            switch (kind)
            {
                case CSSEdge.Left:
                    thickness.Left = width;
                    break;
                case CSSEdge.Top:
                    thickness.Top = width;
                    break;
                case CSSEdge.Right:
                    thickness.Right = width;
                    break;
                case CSSEdge.Bottom:
                    thickness.Bottom = width;
                    break;
                case CSSEdge.All:
                    thickness = new Thickness(width);
                    break;
            }

            border.BorderThickness = thickness;
        }
    }
}
