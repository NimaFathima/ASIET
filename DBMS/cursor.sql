DECLARE
	v_total electricity.total%TYPE;
	CURSOR c IS select * from electricity;
BEGIN
	for i in c loop
		begin 
			if i.unit <=40 then 
				v_total := i.rent;
			elsif  i.unit <=80 then
				v_total := i.rent +(i.unit-40)*0.40;
			else
				v_total := i.rent +(40*0.40)+(i.unit-80)*1.40;DECLARE
	v_total electricity.total%TYPE;
	CURSOR c IS select * from electricity;
BEGIN
	for i in c loop
		begin 
			if i.unit <=40 then 
				v_total := i.rent;
			elsif  i.unit <=80 then
				v_total := i.rent +(i.unit-40)*0.40;
			else
				v_total := i.rent +(40*0.40)+(i.unit-80)*1.40;
			END if;
		
			UPDATE electricity
			set total = v_total
			where cons_id= i.cons_id;
		end;
	end loop;
	commit;
END;
/  

			END if;
		
			UPDATE electricity
			set total = v_total
			where cons_id= i.cons_id;
		end;
	end loop;
	commit;
END;
/  
