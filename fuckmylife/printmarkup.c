#include <stdio.h>
#include <string.h>

struct tag_t
{
	char name[15];
	int is_self_closing;
	struct tag_t *child;
};

void print_markup(struct tag_t);
void add_child(struct tag_t *parent, char name[15], int is_self_closing);

int main(int argc, char const *argv[])
{
	// struct tag_t div = {"div", 0, NULL};
	// struct tag_t body = {"body", 0, &div};
	struct tag_t html = {"html", 0, NULL};
	add_child(&html, "body", 0);
	printf("%p\n", (void *)&html);
	printf("%p\n", (void *)html.child);
	add_child(html.child, "div", 0);
	printf("========\n");
	printf("%p\n", (void *)&html);
	printf("%p\n", (void *)html.child);
	printf("%p\n", (void *)html.child->child);
	//printf("%p\n", html.child->child->child->child->child);
	//print_markup(html);
	return 0;
}

void add_child(struct tag_t *parent, char name[15], int is_self_closing)
{
	if (!parent->is_self_closing)
	{
		static struct tag_t tag;
		strcpy(tag.name, name);
		tag.is_self_closing = is_self_closing;
		tag.child = NULL;
		parent->child = &tag;
		
	}
	
}

void print_markup(struct tag_t tag)
{
	if (tag.is_self_closing)
	{
		printf("<%s/>", tag.name);
	}
	else
	{
		printf("<%s>", tag.name);
		if (tag.child != NULL)
		{
			print_markup(*tag.child);
		}
		printf("</%s>", tag.name);
	}
}
