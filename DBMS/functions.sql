DECLARE
	a number;
	b number;
	c number;

PROCEDURE findMin(x IN number,y IN number,z OUT number) IS
BEGIN
	if x<y then
		z:=x;
	else
		z:=y;
		
	END if;
END;

BEGIN
	a:=23;
	b:=45;
	findMin(a,b,c);
	dbms_output.put_line('Minimum of(23,45):'||c);
END;
/

