#pragma once
int strlen(char * a)
{
	int i = 0;
	if (a != nullptr)
	{
		a[i];
		while (a[i] != '\0')
		{
			i++;
		}
	}

	return i;
}
