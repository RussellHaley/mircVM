#include <stdio.h>
#include "mir.h"
#include "readfile.h"

int interp(char *str)
{
	MIR_module_t m;
	MIR_item_t func;

	MIR_context_t ctx = MIR_init ();

	size_t len = strlen (str);
	MIR_scan_string (ctx, str);
	m = DLIST_TAIL (MIR_module_t, *MIR_get_module_list (ctx));

	MIR_load_module (ctx, m);

	MIR_link (ctx, MIR_set_interp_interface, NULL);

	MIR_val_t val;
	MIR_interp (ctx, func, &val, 0);

	MIR_finish (ctx);

	return 0;
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
	}
	free(str);
	
	printf("That's all folks.\n");
}
