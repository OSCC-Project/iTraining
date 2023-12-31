// ***************************************************************************************
// Copyright (c) 2023-2025 Peng Cheng Laboratory
// Copyright (c) 2023-2025 Institute of Computing Technology, Chinese Academy of Sciences
// Copyright (c) 2023-2025 Beijing Institute of Open Source Chip
//
// iEDA is licensed under Mulan PSL v2.
// You can use this software according to the terms and conditions of the Mulan PSL v2.
// You may obtain a copy of Mulan PSL v2 at:
// http://license.coscl.org.cn/MulanPSL2
//
// THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND,
// EITHER EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT,
// MERCHANTABILITY OR FIT FOR A PARTICULAR PURPOSE.
//
// See the Mulan PSL v2 for more details.
// ***************************************************************************************
#include "LGInstance.hh"

namespace ipl{

LGInstance::LGInstance(std::string name): _name(name), _master(nullptr), _orient(Orient::kNone), _state(LGINSTANCE_STATE::kNone), _belong_cluster(nullptr), _belong_region(nullptr), _weight(1.0){}

LGInstance::~LGInstance()
{

}

void LGInstance::updateCoordi(int32_t llx, int32_t lly){
    _shape = Rectangle<int32_t>(llx, lly, llx + _shape.get_width(), lly + _shape.get_height());
}

}
