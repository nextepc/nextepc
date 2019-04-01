/*************************************************************************** 

    Copyright (C) 2019 NextEPC Inc. All rights reserved.

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU Affero General Public License as
    published by the Free Software Foundation, either version 3 of the
    License, or (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU Affero General Public License for more details.

    You should have received a copy of the GNU Affero General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.

***************************************************************************/


#ifndef __YAML_HELPER_H__
#define __YAML_HELPER_H__

#include "core_debug.h"

#include <yaml.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
    yaml_document_t *document;
    yaml_node_t *node;
    yaml_node_pair_t *pair;
    yaml_node_item_t *item;
} yaml_iter_t;

CORE_DECLARE(void) yaml_iter_init(yaml_iter_t *iter, yaml_document_t *document);
CORE_DECLARE(int) yaml_iter_next(yaml_iter_t *iter);
CORE_DECLARE(void) yaml_iter_recurse(yaml_iter_t *parent, yaml_iter_t *iter);

CORE_DECLARE(int) yaml_iter_type(yaml_iter_t *iter);
CORE_DECLARE(const char *) yaml_iter_key(yaml_iter_t *iter);
CORE_DECLARE(const char *) yaml_iter_value(yaml_iter_t *iter);
CORE_DECLARE(int) yaml_iter_bool(yaml_iter_t *iter);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* __YAML_HELPER_H__ */
