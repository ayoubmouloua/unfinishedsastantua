#include <unistd.h>
#include <stdlib.h>

void	ft_putchar(char c)
{
	write(1,&c,1);
}

int	largeurEtage_i(int i)
{
	if(i == 0)
		return(7);
	return(largeurEtage_i(i - 1) + 2 * (1 + (3 + i) + ((i % 2) + (i / 2 ))));
}

void etage(int	hauteur, int largeur, int decallage)
{
	int i;
	int j;

	i = 0;
	while(i < hauteur)
	{
		j = -decallage;
		while(j < hauteur - 1 - i)
		{
			ft_putchar(' ');
			j++;
		}
		j += hauteur + 1 - i;
		ft_putchar('/');
		while(j < largeur )
		{
			ft_putchar('.');
			j++;
		}
			ft_putchar('\\');
			ft_putchar('\n');
		i++;
	}
}

void sastantua(int size)
{
	int i;
	int hauteur;
	int largeur;
	int decallage;

	i = 0;
	while (i < size)
	{
		decallage = (largeurEtage_i(size - 1) - largeurEtage_i(i)) / 2;
		hauteur = 3 + i;
		largeur = largeurEtage_i(i);
		etage(hauteur, largeur, decallage);
		i++;
	}	
}


int	main(int argc, char **argv)
{
	sastantua(atoi(argv[1]));
	return(0);
}
