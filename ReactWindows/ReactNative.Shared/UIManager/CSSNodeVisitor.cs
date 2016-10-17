using Facebook.CSSLayout;
using System;
using System.Collections.Generic;

namespace ReactNative.UIManager
{
    abstract class CSSNodeVisitor<T>
    {
        public T Visit(CSSNode node)
        {
            if (node == null)
            {
                throw new ArgumentNullException(nameof(node));
            }

            var n = node.Count;
            if (n == 0)
            {
                return Make(node, Array.Empty<T>());
            }
            else
            {
                var children = new List<T>(n);
                for (var i = 0; i < node.Count; i++)
                {
                    children.Add(Visit(node[i]));
                }

                return Make(node, children);
            }
        }

        protected abstract T Make(CSSNode node, IList<T> children);
    }
}
