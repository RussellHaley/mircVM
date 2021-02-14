#include "cvm-tools.h"
#include "mir.h"
#include <string.h>

char *strings[] = {"func", "proto", "import", "export", "forward", "data", "ref_data", "expr_data"};
#define CVM_MIR_ITEM_FUNC 0


static void desc_mir_item(MIR_item_t item, CVM_item_desc_t *idesc)
{
	if(item->item_type == CVM_MIR_ITEM_FUNC)
	{
		(*idesc)->item_name = strdup(item->u.func->name);
	}
	
	(*idesc)->item_type_enum = item->item_type;
	(*idesc)->item_type_name = strdup(strings[item->item_type]);
}

void desc_mir_module(MIR_module_t m, CVM_module_desc_t *mdesc)
{
	int m_items = DLIST_LENGTH(MIR_module_t, m->items);
	mdesc = malloc(sizeof(module_desc) + (sizeof(item_desc) * m_items));
	(*mdesc)->name = strdup(m->name);
	for(int i = 0; i < m_items; i++)
	{
		desc_mir_item(m->items[i], (*mdesc)->items[i]);
	}
}


static void free_item_desc(CVM_item_desc_t item)
{
	free(item->item_name);
	free(item->item_type_name);
}


void free_module_des(CVM_module_desc_t mdesc)
{
	int m_items = DLIST_LENGTH(MIR_module_t, mdesc->items);
	for(int i = 0; i < m_items; i++)
	{
		free_item_desc(mdesc->items[i]);
	}
	free(&mdesc);
}


void show_module_desc(CVM_module_desc_t mdesc)
{
	int m_items = DLIST_LENGTH(CVM_item_desc_t, mdesc->items);
	
	printf("Module name: %s\n", mdesc->name);
	printf("Number of items: %d\n", m_items);
	printf("--------------------------------\n");
	
	
	for(int i =0; i < m_items; i++)
	{
		printf("Item Type: %d\n", mdesc->items[i]->item_type_enum);
		printf("Item Desc: %s\n", mdesc->items[i]->item_type_name);
		if(mdesc->items[i]->item_type_enum == CVM_MIR_ITEM_FUNC)
		{
			printf("Item Name: %s\n", mdesc->items[i]->item_name);
		}
		printf("\n");
	}
}

void debug_module(MIR_module_t m)
{
	CVM_module_desc_t md;
	desc_mir_module(m, &md);
	show_module_desc(md);
	free_module_desc(&md);
}
