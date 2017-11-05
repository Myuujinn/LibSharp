#include "libsharp.h"

int	main()
{
	void	*ptr = gc_malloc(100000, "test");
	void	*ptr2 = gc_malloc(23000, "test");
	void	*ptr3 = gc_malloc(10, "testing");
	void	*ptr4 = gc_malloc(100030, "testay");
	void	*ptr5 = gc_malloc(100, "testay2");
	void	*ptr6 = gc_malloc(10000, "testing");

	gc_print();
	gc_free_hash("test");
	gc_print();
	gc_free();

	LIST	testlist = list_create(STRING_LIST);
	list_add(testlist, "e");
	list_add(testlist, "de");
	list_add(testlist, "cde");
	list_add(testlist, "bcde");
	list_add(testlist, "abdce");
	list_print(testlist);
	list_sort(testlist);
	list_print(testlist);
	list_destroy(testlist);
}
