// Copyright (c) Microsoft Corporation. All rights reserved.
// Licensed under the MIT License.

#pragma once
#include <map>
#include <ShadowNode.h>

namespace facebook {
namespace react {

class IViewManager;

struct ShadowNodeDeleter
{
	void operator()(LegacyShadowNode* node);
};

using shadow_ptr = std::unique_ptr<LegacyShadowNode, ShadowNodeDeleter>;

struct ShadowNodeRegistry
{
	void addRootView(std::unique_ptr<LegacyShadowNode, ShadowNodeDeleter>&& root, int64_t rootViewTag);
	LegacyShadowNode& getRoot(int64_t rootViewTag);
	void removeRootView(int64_t rootViewTag);

	void addNode(std::unique_ptr<LegacyShadowNode, ShadowNodeDeleter>&& node, int64_t tag);
	LegacyShadowNode& getNode(int64_t tag);
	LegacyShadowNode* findNode(int64_t tag);
	void removeNode(int64_t tag);

	void removeAllRootViews(const std::function<void(int64_t rootViewTag)>&);

	std::unordered_set<int64_t>& getAllRoots();

private:
	std::unordered_set<int64_t> m_roots;
	std::map<int64_t, std::unique_ptr<LegacyShadowNode, ShadowNodeDeleter>> m_allNodes;

};

}}
