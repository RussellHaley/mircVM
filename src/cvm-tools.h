#ifndef _CVM_MIR_TOOLS_H
#define _CVM_MIR_TOOLS_H
#include "mir.h"



#define ITEM_EL(i) CVM_##i##_item_desc


typedef struct item_desc *CVM_item_desc_t;


DEF_DLIST_LINK (CVM_item_desc_t);

struct item_desc{
	char *item_name;
	char *item_type_name;
	int  item_type_enum;
	DLIST_LINK(CVM_item_desc_t) items_link;
};


DEF_DLIST(CVM_item_desc_t, items_link);

struct module_desc{
	char *name;
	DLIST(CVM_item_desc_t) items;
};

typedef struct module_desc *CVM_module_desc_t;

void desc_mir_module(MIR_module_t m, CVM_module_desc_t *mdesc);
//~ void desc_mir_item(MIR_item_t item, CVM_module_desc_t *idesc);
void free_module_desc(CVM_module_desc_t mdesc);

#endif //_CVM_MIR_TOOLS_H
