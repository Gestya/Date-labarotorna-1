#pragma once
#include "Data.h"

struct tree
{
	Data d;
	tree *left{ nullptr };
	tree *right{ nullptr };
	tree *parent{ nullptr };
};