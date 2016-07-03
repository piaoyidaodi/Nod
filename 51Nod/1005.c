#include <stdio.h>
#include <string.h>

int ini(char * p);
int minus_spl(char *, char *, char *, int, int);
int minus_nml(char *, char *, char *, int, int);
int minus_equ(char *, char *, char *, int);
int plus(char *, char *, char *, int, int);
char* to_end(char *, char *);

int main(void)
{
	char a[10005], b[10005], c[10005], *p, *q, *r;
	int count_a, count_b, count_c, i;
	p = a;
	q = b;
	r = c;
	count_a = ini(a);
	count_b = ini(b);
	count_c = 0;
	if ((a[0] == '-' && b[0] != '-') || (b[0] == '-' && a[0] != '-'))
	{
		if (((count_a > count_b) && (a[0] == '-')) || ((count_a < count_b) && (b[0] == '-')))
		{
			minus_spl(a, b, c, count_a, count_b);
		}
		else if (count_a == count_b)
		{
			minus_equ(a, b, c, count_a);
		}
		else
		{
			minus_nml(a, b, c, count_a, count_b);
		}
	}
	else
	{
		if (a[0] == '-' && b[0] == '-')
		{
			a[0] = b[0] = '0';
			plus(a, b, c, count_a, count_b);
			r = c;
			while (*r != '\0')
			{
				r++;
			}
			*r = '-';
			r++;
			*r = '\0';
		}
		else
		{
			plus(a, b, c, count_a, count_b);
		}
	}
	r = c;
	while (*r != '\0')
	{
		r++;
		count_c++;
	}
	r--;
	for (i = count_c - 1; i >= 0; i--)
	{
		printf("%c", c[i]);
	}
	printf("\n");
	return 0;
}

int ini(char * p)
{
	int count = 0;
	*p = getchar();
	while (*p != '\n')
	{
		if (*p != '-')
		{
			count++;
		}
		p++;
		*p = getchar();
	}
	*p = '\0';
	return count;
}

int minus_spl(char *a, char *b, char *c, int count_a, int count_b)
{
	int flag, count, tmp;
	flag = 0;
	char *p, *q, *r;
	p = a;
	q = b;
	r = c;
	p = to_end(a, p);
	q = to_end(b, q);
	count = (count_a <= count_b) ? count_a : count_b;
	if (count_a > count_b)
	{
		while (count != 0)
		{
			tmp = int(*p) - int(*q);
			if (tmp < flag)
			{
				tmp = (tmp + 48) + 10 - flag;
				*r = char(tmp);
				r++;
				flag = 1;
			}
			else
			{
				tmp = (tmp + 48) - flag;
				*r = char(tmp);
				r++;
				flag = 0;
			}
			p--;
			q--;
			count--;
		}
		count = count_b;
		if (flag == 1)
		{
			while (flag == 1 && p != (a + 1))
			{
				tmp = int(*p);
				if (tmp - 48 == 0)
				{
					tmp = tmp + 10 - flag;
					*r = char(tmp);
					r++;
					flag = 1;
				}
				else
				{
					tmp = tmp - flag;
					*r = char(tmp);
					r++;
					flag = 0;
				}
				p--;
			}
			if (p == (a + 1) && flag == 1)
			{
				if (a[1] == '1')
				{
					*(r++) = '-';
					*r = '\0';
				}
				else
				{
					*r = char(int(a[0]) - 1);
					*(r++) = '-';
					*r = '\0';
				}
			}
		}
		if (flag == 0)
		{
			while (p != a)
			{
				*(r++) = *p;
				p--;
			}
			*(r++) = a[0];
			*r = '\0';
		}
	}
	if (count_b > count_a)
	{
		while (count != 0)
		{
			tmp = int(*q) - int(*p);
			if (*q - flag < *p)
			{
				tmp += 48 + 10 - flag;
				*r = char(tmp);
				r++;
				flag = 1;
			}
			else
			{
				tmp = tmp + 48 - flag;
				*r = char(tmp);
				r++;
				flag = 0;
			}
			p--;
			q--;
			count--;
		}
		count = count_a;
		if (flag == 1)
		{
			while (flag == 1 && q != b + 1)
			{
				tmp = int(*q);
				if (tmp == 48)
				{
					tmp = tmp + 10 - flag;
					*r = char(tmp);
					r++;
					flag = 1;
				}
				else
				{
					tmp = tmp - flag;
					*r = char(tmp);
					r++;
					flag = 0;
				}
				q--;
			}
			if (q == b + 1 && flag == 1)
			{
				if (b[1] == '1')
				{
					*(r++) = '-';
					*r = '\0';
				}
				else
				{
					*r = char(int(b[0]) - 1);
					*(r++) = '-';
					*r = '\0';
				}
			}
		}
		if (flag == 0)
		{
			while (q != b)
			{
				*(r++) = *q;
				q--;
			}
			*(r++) = b[0];
			*r = '\0';
		}
	}
	return 0;
}

int plus(char *a, char *b, char *c, int count_a, int count_b)
{
	int flag, count, tmp;
	flag = 0;
	char *p, *q, *r;
	p = a;
	q = b;
	p = to_end(a, p);
	q = to_end(b, q);
	r = c;
	count = (count_a <= count_b) ? count_a : count_b;
	while (count != 0)
	{
		tmp = (int(*p) - 48) + (int(*q) - 48) + flag;
		if (tmp >= 10)
		{
			tmp = tmp % 10 + 48;
			*r = char(tmp);
			r++;
			flag = 1;
		}
		else
		{
			tmp = tmp + 48;
			*r = char(tmp);
			r++;
			flag = 0;
		}
		p--;
		q--;
		count--;
	}
	count = (count_a <= count_b) ? count_a : count_b;
	if ((flag == 0) && (count_a > count_b))
	{
		while (p != a)
		{
			*r = *p;
			r++;
			p--;
		}
		*r = *p;
		if (*r == '0')
		{
			*r = '\0';
		}
		else
		{
			r++;
			*r = '\0';
		}
	}
	if ((flag == 0) && (count_a < count_b))
	{
		while (q != b)
		{
			*r = *q;
			r++;
			q--;
		}
		*r = *q;
		if (*r == '0')
		{
			*r = '\0';
		}
		else
		{
			r++;
			*r = '\0';
		}
	}
	if ((flag == 0) && (count_a = count_b))
	{
		*r = '\0';
	}

	if ((flag == 1) && (count_a > count_b))
	{
		while (flag == 1 && p != a)
		{
			tmp = int(*p) - 48 + flag;
			if (tmp >= 10)
			{
				tmp = tmp % 10 + 48;
				*r = char(tmp);
				r++;
				flag = 1;
			}
			else
			{
				tmp = tmp + 48;
				*r = char(tmp);
				r++;
				flag = 0;
			}
			p--;
		}
		if (p == a && flag == 1)
		{
			if (int(*p)-48+flag==10)
			{
				*(r++) = '0';
				*(r++) = '1';
				*r = '\0';
			}
			else
			{
				*r = char(int(*p) + 1);
				r++;
				*r = '\0';
			}
			
		}
		else
		{
			while (p != a)
			{
				*r = *p;
				r++;
				p--;
			}
			*r = *p;
			if (*r == '0')
			{
				*r = '\0';
			}
			else
			{
				r++;
				*r = '\0';
			}
		}
	}
	if ((flag == 1) && (count_a < count_b))
	{
		while (flag == 1 && q != b)
		{
			tmp = int(*q) - 48 + flag;
			if (tmp >= 10)
			{
				tmp = tmp % 10 + 48;
				*r = char(tmp);
				r++;
				flag = 1;
			}
			else
			{
				tmp = tmp + 48;
				*r = char(tmp);
				r++;
				flag = 0;
			}
			q--;
		}
		if (q == b && flag == 1)
		{
			*r = char(int(*q) + 1);
			r++;
			*r = '\0';
		}
		else
		{
			while (q != b)
			{
				*r = *q;
				r++;
				q--;
			}
			*r = *q;
			if (*r == '0')
			{
				*r = '\0';
			}
			else
			{
				r++;
				*r = '\0';
			}
		}
	}
	if ((flag == 1) && (count_a == count_b))
	{
		*(r++) = '1';
		*r = '\0';
	}
	return 0;
}

int minus_equ(char *a, char *b, char *c, int count)
{
	int flag, counter, tmp, smb;
	flag = 0;
	smb = 0;
	char *p, *q, *r;
	p = a;
	q = b;
	r = c;
	if (a[0] == '-')
	{
		p++;
	}
	else q++;
	while (1)
	{
		if (*p > *q)
		{
			p = a;
			q = b;
			if (a[0] == '-')
			{
				smb = 1;
			}
			p = to_end(a, p);
			q = to_end(b, q);
			break;
		}
		else if (*p < *q)
		{
			p = b;
			q = a;
			if (b[0] == '-')
			{
				smb = 1;
			}
			p = to_end(b, p);
			q = to_end(a, q);
			break;
		}
		else if (*p == '\0')
		{
			*(c++) = '0';
			*c = '\0';
			return 0;
		}
		p++;
		q++;
	}
	counter = count;
	while (counter != 0)
	{
		tmp = int(*p) - int(*q);
		if (tmp < flag)
		{
			tmp = (tmp + 48) + 10 - flag;
			*r = char(tmp);
			r++;
			flag = 1;
		}
		else
		{
			tmp = (tmp + 48) - flag;
			*r = char(tmp);
			r++;
			flag = 0;
		}
		p--;
		q--;
		counter--;
	}
	*(r--) = '\0';
	while (r != c)
	{
		if (*r != '0')
		{
			break;
		}
		r--;
	}
	if (r == c)
	{
		if (*r == '0')
		{
			r++;
			*r = '\0';
		}
		else
		{
			if (smb == 1)
			{
				r++;
				*(r++) = '-';
				*r = '\0';
			}
			else
			{
				r++;
				*r = '\0';
			}
		}
	}
	else
	{
		if (smb == 1)
		{
			r++;
			*(r++) = '-';
			*r = '\0';
		}
		else
		{
			r++;
			*r = '\0';
		}
	}
	return 0;
}

int minus_nml(char *a, char *b, char *c, int count_a, int count_b)
{
	int flag, count, tmp;
	flag = 0;
	char *p, *q, *r;
	p = a;
	q = b;
	r = c;
	p = to_end(a, p);
	q = to_end(b, q);
	count = (count_a <= count_b) ? count_a : count_b;
	if (count_a > count_b)
	{
		while (count != 0)
		{
			tmp = int(*p) - int(*q);
			if (tmp < flag)
			{
				tmp = (tmp + 48) + 10 - flag;
				*r = char(tmp);
				r++;
				flag = 1;
			}
			else
			{
				tmp = (tmp + 48) - flag;
				*r = char(tmp);
				r++;
				flag = 0;
			}
			p--;
			q--;
			count--;
		}
		count = count_b;
		if (flag == 1)
		{
			while (flag == 1 && p != a)
			{
				tmp = int(*p);
				if (tmp - 48 == 0)
				{
					tmp = tmp + 10 - flag;
					*r = char(tmp);
					r++;
					flag = 1;
				}
				else
				{
					tmp = tmp - flag;
					*r = char(tmp);
					r++;
					flag = 0;
				}
				p--;
			}
			if (p == a && flag == 1)
			{
				if (a[0] == '1')
				{
					*r = '\0';
				}
				else
				{
					*r = char(int(a[0]) - 1);
					r++;
					*r = '\0';
				}
			}
		}
		if (flag == 0)
		{
			while (p != a)
			{
				*(r++) = *p;
				p--;
			}
			*(r++) = a[0];
			*r = '\0';
		}
	}
	if (count_b > count_a)
	{
		while (count != 0)
		{
			tmp = int(*q) - int(*p);
			if (*q - flag < *p)
			{
				tmp += 48 + 10 - flag;
				*r = char(tmp);
				r++;
				flag = 1;
			}
			else
			{
				tmp = tmp + 48 - flag;
				*r = char(tmp);
				r++;
				flag = 0;
			}
			p--;
			q--;
			count--;
		}
		count = count_a;
		if (flag == 1)
		{
			while (flag == 1 && q != b)
			{
				tmp = int(*q);
				if (tmp == 48)
				{
					tmp = tmp + 10 - flag;
					*r = char(tmp);
					r++;
					flag = 1;
				}
				else
				{
					tmp = tmp - flag;
					*r = char(tmp);
					r++;
					flag = 0;
				}
				q--;
			}
			if (q == b && flag == 1)
			{
				if (b[0] == '1')
				{
					 *r = '\0'; 
					 r--;
					 while (r != c)
					 {
						 if (*r != '0')
						 {
							 r++;
							 break;
						 }
						 r--;
					 }
					 if (r == c)
					 {
						 if (*r != '0')
						 {
							 r++;
							 *r = '\0';
						 }
					 }
					 else
					 {
						 *r = '\0';
					 }
				}
				else
				{
					*r = char(int(b[0]) - 1);
					r++;
					*r = '\0';
				}
			}
		}
		if (flag == 0)
		{
			while (q != b)
			{
				*(r++) = char(*q);
				q--;
			}
			*(r++) = b[0];
			*r = '\0';
		}
	}
	return 0;
}

char* to_end(char *aray, char *p)
{
	p = aray;
	while (*p != '\0')
		p++;
	p--;
	return p;
}