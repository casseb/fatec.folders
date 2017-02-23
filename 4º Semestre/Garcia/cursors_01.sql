
create or replace package Employees_Cur_Static_Sql is
  type Last_Names_Tab_t is table of employees.last_name%type
    index by binary_integer;

  function Fetch_All_Rows ( p_department_id in employees.department_id%type )
    return Last_Names_Tab_t;

end Employees_Cur_Static_Sql;
/
Show Errors

create or replace package body Employees_Cur_Static_Sql is

  function Fetch_All_Rows ( p_department_id in employees.department_id%type )
     return Last_Names_Tab_t
  is
    v_last_names_tab Last_Names_Tab_t;
    cursor c_employees is
      select last_name from employees where department_id = p_department_id;

  begin
    open c_employees;
    fetch c_employees bulk collect into v_last_names_tab;
    close c_employees;
    return v_last_names_tab;
  end Fetch_All_Rows;

end Employees_Cur_Static_Sql;
/
Show Errors


