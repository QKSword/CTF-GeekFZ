#include <stdio.h>
#include <windows.h>


void check_2(char flag[])
{
	if(flag[0] == 't')
	{
		if(flag[1] == 'f')
		{
			if(flag[2] == 'o')
			{
				if(flag[3] == 'Q')
				{
					if(flag[4] == '5')
					{
						if(flag[5] == 'c')
						{
							if(flag[6] == 'k')
							{
								if(flag[7] == 'k')
								{
									if(flag[8] == 'w')
									{
										if(flag[9] == 'h')
										{
											if(flag[10] == 'X')
											{
												if(flag[11] == '5')
												{
													if(flag[12] == '1')
													{
														if(flag[13] == 'H')
														{
															if(flag[14] == 'Y')
															{
																if(flag[15] == 'p')
																{
																	if(flag[16] == 'x')
																	{
																		if(flag[17] == 'A')
																		{
																			if(flag[18] == 'j')
																			{
																				if(flag[19] == 'k')
																				{
																					if(flag[20] == 'M')
																					{
																						if(flag[21] == 'Q')
																						{
																							if(flag[22] == 'Y')
																							{
																								if(flag[23] == 'T')
																								{
																									if(flag[24] == 'A')
																									{
																										if(flag[25] == 'p')
																										{
																											if(flag[26] == '5')
																											{
																												printf("yes, this is a flag\n");
																												getchar();
																											}
																										}
																									}
																								}
																							}
																						}
																					}
																				}
																			}
																		}
																	}
																}
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
}



void check(char flag[])
{
	char key1[65] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
	char key2[65] = "+/abcdefghijklmnopqrstuvwxyz0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char key3[65] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789+/";
	char key4[65] = "0123456789+/ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";

	char key[27] = "QASWZXDECVFRBNGTHYJUMKIOLP";
	int len = strlen(flag);
	for(int i=0; i<len; i++)
	{
		if(int(flag[i]) <= 126 && int(flag[i]) >= 33)
		{
			if(flag[i]-key[i] > 0)
			{
				int the_key = (flag[i]-key[i]) % 4;
				switch (the_key)
				{
					case 0:
						flag[i] = key1[flag[i]-key[i]];
						continue;
					case 1:
						flag[i] = key2[flag[i]-key[i]];
						continue;
					case 2:
						flag[i] = key3[flag[i]-key[i]];
						continue;
					case 3:
						flag[i] = key4[flag[i]-key[i]];
						continue;
					default:
						continue;
				}				
			}
			else
			{
				printf("flag is wrong");
				ExitProcess(0);
			}
		}
	}
	//printf("%s",flag);
	check_2(flag);
}

int main()
{
	char flag[MAX_PATH];

	printf("输入flag：");
	gets_s(flag);
	if(strlen(flag) >= 28)
	{
		printf("输入flag太长");
		return 0;
	}
	else
	{
		check(flag);
		return 0;
	}
	return 0;
}