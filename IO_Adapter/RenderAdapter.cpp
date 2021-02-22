#include "RenderAdapter.h"

RenderAdapter::RenderAdapter(const int& width, const int& height) : width(width), height(height) {}
RenderAdapter::~RenderAdapter() {}

const int RenderAdapter::GetWidth() { return width; }
const int RenderAdapter::GetHeight() { return height; }