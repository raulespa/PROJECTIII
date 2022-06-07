#include <iostream>
#include <mysql.h>

using namespace std;

char serverdb[] = "localhost";
char userdb[] = "umg";
char passworddb[] = "Umg$2019";
char database[] = "proyecto2";

int main() {
	MYSQL* connection;
	MYSQL_ROW row;
	MYSQL_RES* data;
	string ALUMNO_ID;
	string NOMBRE_COMPLETO;
	string CORREO;
	string CARNE;
	string FECHA_NACIMIENTO;
	string DIRECCION;
	string NUM_TELEFONO;
	string PROMEDIO;
	string SECCION;
	string sql;
	int b;
	
	
	const char* query;
	int result;
	int op; 
	connection = mysql_init(0);
	if (connection)
	{
		cout << "BIENVENIDO AL POYECTO FINAL" << endl;
			cout << "RAUL GONZALEZ / FERDINAND REYNA / ESTEBAN ORELLANA" << endl;
		connection = mysql_real_connect(connection, serverdb, userdb, passworddb, database, 3306, NULL, 0);
		if (connection)
		{
			cout << "\n CONEXION EXITOSA CON LA BASE DE DATOS...." << endl;
			
			int op;
			
		    while(op != 10)
			{
				cout <<"\n\n";
				cout << "1) Igresar Alumno"<< endl;
				cout << "2) Buscar Alumno"<< endl;
				cout << "3) Modificar datos de un alumno" << endl;
				cout << "4) listar Alumnos"<< endl;
				cout << "5) Eliminar Alumno"<< endl;
				cout << "6) Deshacer ultimos cambios"<< endl;
				cout << "7) Rehacer Cambios" << endl;
				cout << "8) listar cambios realizados"<< endl;
				cout << "10) Salir"<<endl;
				cout << "SELECCIONE UNA OPCION\n" << endl;
				cin>> op;
				
				switch(op)
				{
					case 1: 
					cout << "ingrese el nombre del alumno: "<<endl;
					cin.ignore();
					getline(cin, NOMBRE_COMPLETO);
					cout << "ingrese el correo del alumno: "<<endl;
					getline(cin, CORREO);
					cout << "ingrese el carne del alumno (7 digitos: codigo de carrera + año inicio + correlativo de carrera): "<<endl;
					cout << "ejemplo del numero de carne 85-2022-8" <<endl;
					getline(cin, CARNE);
					cout << "ingrese la fecha de nacimiento del alumno (YY-MM-DD): "<<endl;
					getline(cin, FECHA_NACIMIENTO);
					cout << "ingrese el numero de telefono del alumno: "<<endl;
					getline(cin, NUM_TELEFONO);
					cout << "ingrese la direccion del alumno: "<<endl;
					getline(cin, DIRECCION);
					
					int op; 	
					while(op !=2)
					{
						cout << "que desea hacer con los cambios ingresados???"<< endl; 
						cout << "1) guardar cambios..." <<endl;
						cout << "11) deshacer cambios..." <<endl;
						cin >> op;
						
						switch (op)
						
						
						case 1: 	
					sql = "insert into alumno(NOMBRE_COMPLETO, CORREO, CARNE, FECHA_NACIMIENTO, NUM_TELEFONO, DIRECCION)  VALUES ( '" + NOMBRE_COMPLETO +"' , '" + CORREO +"'  , '" + CARNE +"' ,  '" + FECHA_NACIMIENTO + "' ,'" + NUM_TELEFONO +"' , '" + DIRECCION +"' )";
					query = sql.c_str();
					result = mysql_query(connection, query);
					if (result == 0)
					{
					cout << "se ha registrado al alumno\n\n";
					}		 
					else
					{
			   	    cout << "no se ha registrado el alumno " <<  endl; 
					}
					system("pause");
					system("cls");
					return main();
					break;
					
					case 11:
				    cout <<"no se ha podido guardar los cambios"<<endl;
				    system("cls");
				    return main();
				    break;
					}	
						
				
					break;
					
					
					case 2:
					cout << "ingrese el ID del alumno que desea  buscar " <<endl;
					cin.ignore();
					getline(cin, ALUMNO_ID);
					sql = "select NOMBRE_COMPLETO, CORREO, CARNE, FECHA_NACIMIENTO, NUM_TELEFONO, DIRECCION from ALUMNO where ALUMNO_ID  = ( '" + ALUMNO_ID +"')";
					query = sql.c_str();
					result = mysql_query(connection, query);
						{  
						cout << "EL ALUMNO QUE USTED BUSCA ES: " <<endl;
						data = mysql_store_result(connection);
						int countColumns = mysql_num_fields(data);
						while(row = mysql_fetch_row(data))
						{
								for (int i = 0; i < countColumns; i++)
								{
									cout << row[i] << "\t";
								}
								cout <<endl;
						}
					}
					system("pause");
					system("cls");
					return main();
					break;
					
					case 3:
					cout << "ingrese el ID del alumno: "<<endl;
					cin.ignore();
					getline(cin, ALUMNO_ID);
					cout << "ingrese el nombre del alumno: "<<endl;
					getline(cin, NOMBRE_COMPLETO);
					cout << "ingrese el correo del alumno: "<<endl;
					getline(cin, CORREO);
					cout << "ingrese el carne del alumno (7 digitos: codigo de carrera + año inicio + correlativo de carrera): "<<endl;
					cout << "ejemplo del numero de carne 85-2022-8" <<endl;
					getline(cin, CARNE);
					cout << "ingrese la fecha de nacimiento del alumno (YY-MM-DD): "<<endl;
					getline(cin, FECHA_NACIMIENTO);
					cout << "ingrese el numero de telefono del alumno: "<<endl;
					getline(cin, NUM_TELEFONO);
					cout << "ingrese la direccion del alumno: "<<endl;
					getline(cin, DIRECCION);
						
					while(op !=2)
					{
						cout << "que desea hacer con los cambios ingresados???"<< endl; 
						cout << "1) guardar cambios..." <<endl;
						cout << "13) deshacer cambios..." <<endl;
						cin >> op;
						
						switch (op)
						
						
						case 1: 	
					sql = "UPDATE ALUMNO SET NOMBRE_COMPLETO='" + NOMBRE_COMPLETO +"' , CORREO='" + CORREO +"'  , CARNE= '" + CARNE +"' ,  FECHA_NACIMIENTO='" + FECHA_NACIMIENTO + "' ,NUM_TELEFONO='" + NUM_TELEFONO +"' , DIRECCION='" + DIRECCION +"' WHERE ALUMNO_ID ='" + ALUMNO_ID +"'";
					query = sql.c_str();
					result = mysql_query(connection, query);
					if (result == 0)
					{
					cout << "se ha ACTUALIZADO al alumno\n\n";
					}		 
					else
					{
			   	    cout << "no se ha podido ACTUALIZAR al alumno " << endl;  
					}
					system("pause");
					system("cls");
					return main();
					break;
					
					case 13:
				    cout <<"no se ha podido guardar los cambios"<<endl;
				    system("cls");
				    return main();
				    break;
					}	
					
					break;
				
					case 4:
					sql = "SELECT * FROM ALUMNO";
					query = sql.c_str();
					result = mysql_query(connection, query);
					if (result == 0)
					{  
						cout << "el listado de alumnos es: \n" <<endl;
						data = mysql_store_result(connection);
						int countColumns = mysql_num_fields(data);
						while(row = mysql_fetch_row(data))
						{
								for (int i = 0; i < countColumns; i++)
								{
									cout << row[i] << "\t";
								}
								cout <<endl;
						}
					}
					system("pause");
					system("cls");
					return main();
					break;
					
					case 5: 
					
					
					cout << "ingrese el ID del alumno que desea eliminar\n " <<endl;
					cin.ignore();
					getline(cin, ALUMNO_ID);
	
					while(op !=2)
					{
						cout << "que desea hacer con los cambios ingresados???"<< endl; 
						cout << "1) guardar cambios..." <<endl;
						cout << "12) deshacer cambios..." <<endl;
						cin >> op;
						
						switch (op)
						
						
						case 1: 	
					sql = "delete from alumno where ALUMNO_ID = ( '" + ALUMNO_ID +"')";
					query = sql.c_str();
					result = mysql_query(connection, query);
					if (result == 0)
					{
					cout << "se ha eliminado al alumno\n\n";
					}		 
					else
					{
			   	    cout << "no se han guardado los cambios para eliminar al alumno " << endl;
					}
					system("pause");
					system("cls");
					return main();
					break;
					
					case 8:
					cout <<"los cambios que usted realizo fueron: AGREGAR ALUMNO, MODIFICAR DATOS DE ALUMNO Y ELIMINAR ALUMNO"<<endl;
					system("pause");
					system("cls");
					return main();
					break;
					
					case 12:
				    cout <<"no se ha podido guardar los cambios"<<endl;
				    system("cls");
				    return main();
				    break;
					}
					
					break;
					
					case 10:
					cout << "has guardado los cambios efectuados?? 1=si cualquier otro numero=no"<<endl;
					cin >>b;
					if (b==1)
					{
					exit(1);
					system("pause");
					}
					else
					{
					cout <<"debes de guardar los cambios antes de salir para que se puedan efectuar" <<endl;
					system ("cls");
					return main();
					break;	
					}		
			    }
			    
			    	
				
							
			 } 		
		}	
		else 
		{
		cout << "no fue posible conectar con la base de datos" << mysql_error(connection) << endl;
		}
	}
	else 
	{
		cout << "no sirve la conexion" << endl; 
	}
return 0;
}


