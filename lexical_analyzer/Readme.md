This is a simple(not well-completed) lexical analyer.

The test program is as follows:

```C
{
	i = 2;
	while (i <= 100)
	{
		sum = sum + i;
		i = i + 2;
	}
}
```

This analyzer can analyse following words:
- number types: int（including hex), float, science-num;
- identifiers and keywords(can be extended in the program)
- common opertors, including both unary and binary operator.
