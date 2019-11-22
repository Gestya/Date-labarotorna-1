#pragma once
#include "date.h"

struct tree
{
		date d; 
		tree *left{ nullptr };
		tree *right{ nullptr };
		tree *parent{ nullptr };
};