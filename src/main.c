#include <stdio.h>
#include "mir.h"
#include "readfile.h"

int interp(char *str)
{
	int retval = 0;
	MIR_module_t m;
	MIR_item_t func;

	MIR_context_t ctx = MIR_init ();

	size_t len = strlen (str);
	MIR_scan_string (ctx, str);
	m = DLIST_TAIL (MIR_module_t, *MIR_get_module_list (ctx));
	if(m == NULL)
	{
		printf("Failed to get the module items\n");
		retval = 2;
	}
	else
	{
		func = DLIST_TAIL (MIR_item_t, m->items); 
		if(func == NULL)
		{
			printf("WTH?");
		}
		else
		{
			printf("enum val %d\n", func->item_type);
		}
		MIR_load_module (ctx, m);
		MIR_load_external (ctx, "printf", printf);
		MIR_link (ctx, MIR_set_interp_interface, NULL);

		MIR_val_t val;
		MIR_interp (ctx, func, &val, 0);
	}
	MIR_finish (ctx);

	return retval;
}

int main(int argc, char** argv)
{
	char *str;
	if(argc > 1)
	{
		if(readfile(argv[1], &str) == 0)
		{
			//~ printf("not cool %s", str);
			interp(str);
		}
	}
	else
	{
		printf("Need to pass a filename\n");
		return 1;
	}
	
	if(str != NULL) free(str);

	printf("That's all folks.\n");
	return 0;
}
