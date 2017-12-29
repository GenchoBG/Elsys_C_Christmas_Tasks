#include <stdio.h>

typedef struct 
{
	char type;
	char size;
	int price; // should't price be float? :thinking:
} barbaron_t;

typedef struct
{
	barbaron_t barbarons[10];
	int count;
} barbaron_shop_t;

void add_barbaron(barbaron_shop_t *, barbaron_t);
barbaron_t buy_barbaron(barbaron_shop_t *shop, char, char, int*);

int main(int argc, char const *argv[])
{
	barbaron_t Pesho = {'P', 'L', 69};
	barbaron_shop_t shop;
	shop.count = 0;
	add_barbaron(&shop, Pesho);
	printf("%d\n", shop.barbarons[0].price);
	printf("%d\n", shop.count);
	int money = 10000;
	barbaron_t bought = buy_barbaron(&shop, 'P', 'L', &money);
	printf("%c\n", bought.type);	
	printf("%c\n", bought.size);	
	printf("%d\n", bought.price);
	printf("%d\n", money);	
}

void add_barbaron(barbaron_shop_t *shop, barbaron_t barb)
{
	if (shop->count < 10)
	{
		shop->barbarons[shop->count++] = barb;
	}
}

barbaron_t buy_barbaron(barbaron_shop_t *shop, char type, char size, int *money)
{
	for (int i = 0; i < shop->count; ++i)
	{
		barbaron_t current = shop->barbarons[i];
		if (current.type == type && current.size == size && current.price <= *money)
		{
			*money -= current.price;
			return current;
		}
	}

	barbaron_t some_retarded_value_so_it_doesnt_give_me_an_warning_c_is_trash;
	return some_retarded_value_so_it_doesnt_give_me_an_warning_c_is_trash;
}
