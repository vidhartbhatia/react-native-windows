// Copyright (c) Microsoft Corporation. All rights reserved.
// Licensed under the MIT License.

#include "ShadowNodeRegistry.h"
#include "ShadowNode.h"
#include "ViewManager.h"

namespace facebook { namespace react {

void ShadowNodeDeleter::operator()(LegacyShadowNode* node)
{
	if (node->m_viewManager)
		node->m_viewManager->destroyShadow(node);
}

void ShadowNodeRegistry::addRootView(std::unique_ptr<LegacyShadowNode, ShadowNodeDeleter>&& root, int64_t rootViewTag)
{
	m_roots.insert(rootViewTag);
	m_allNodes[rootViewTag] = std::move(root);
}

LegacyShadowNode& ShadowNodeRegistry::getRoot(int64_t rootViewTag)
{
	CHECK(m_roots.find(rootViewTag) != m_roots.end());
	return getNode(rootViewTag);
}

void ShadowNodeRegistry::removeRootView(int64_t rootViewTag)
{
	m_roots.erase(rootViewTag);
	removeNode(rootViewTag);
}

void ShadowNodeRegistry::addNode(std::unique_ptr<LegacyShadowNode, ShadowNodeDeleter>&& node, int64_t tag)
{
	m_allNodes[tag] = std::move(node);
}

LegacyShadowNode* ShadowNodeRegistry::findNode(int64_t tag)
{
	auto iter = m_allNodes.find(tag);
	return (iter != m_allNodes.end()) ? iter->second.get() : nullptr;
}

LegacyShadowNode& ShadowNodeRegistry::getNode(int64_t tag)
{
	return *m_allNodes.at(tag);
}

void ShadowNodeRegistry::removeNode(int64_t tag)
{
	m_allNodes.erase(tag);
}

void ShadowNodeRegistry::removeAllRootViews(const std::function<void(int64_t rootViewTag)>& fn)
{
	while (!m_roots.empty())
		fn(*m_roots.begin());
}

std::unordered_set<int64_t>& ShadowNodeRegistry::getAllRoots()
{
  return m_roots;
}


}
}
