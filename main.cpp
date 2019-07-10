// Copyright 2019

#include <sqlite3.h>
#include <iostream>


static int callback(void *NotUsed, int argc, char **argv, char **azColName) {
    for (int i = 0; i < argc; i++) {
        std::cout << azColName[i] << " = " << (argv[i] ? argv[i] : "NULL");
        std::cout << std::endl;
    }
    std::cout << std::endl;
    return 0;
}

static int callback2(void *count, int argc, char **argv, char **azColName) {
    auto *c = reinterpret_cast<int *>(count);
    // *c = std::strtol(argv[0], &argv[0], 10);
    *c = std::stoi(argv[0]);
    return 0;
}


void addPlayer(sqlite3 *db, char *zErrMsg) {
    std::string sql, nombre, posicion;
    int edad, numero, rc;

    std::cout << "Teclee nombre: " << std::endl;
    std::cin >> nombre;

    std::cout << "Teclee edad: " << std::endl;
    std::cin >> edad;

    std::cout << "Teclee numero: " << std::endl;
    std::cin >> numero;

    std::cout << "Teclee posicion: " << std::endl;
    std::cin >> posicion;

    sql = "INSERT INTO jugadores (NOMBRE,EDAD,NUMERO,POSICION) VALUES " \
    "('"+ nombre +"', " + std::to_string(edad) + ", " +
    std::to_string(numero) + ", '" + posicion + "' );";

    rc = sqlite3_exec(db, sql.c_str(), callback, nullptr, &zErrMsg);

    if (rc != SQLITE_OK) {
        std::cout << "SQL error: " << zErrMsg << std::endl;
        sqlite3_free(zErrMsg);
    } else {
        std::cout << "Guardado correctamente" << std::endl;
    }
}

void deletePlayer(sqlite3 *db, char *zErrMsg) {
    std::string sql, sql_temp;
    int numero, rc, count = 0;

    std::cout << "Teclee numero del jugador a eliminar: " << std::endl;
    std::cin >> numero;

    sql_temp = "SELECT count(*) FROM jugadores WHERE NUMERO="
            + std::to_string(numero) +";";

    rc = sqlite3_exec(db, sql_temp.c_str(), callback2, &count, &zErrMsg);

    if (rc != SQLITE_OK) {
        std::cout << "SQL error: " << std::endl;
        sqlite3_free(zErrMsg);
    }

    if (count != 0) {
        sql = "DELETE FROM jugadores WHERE NUMERO="
                + std::to_string(numero) +";";

        rc = sqlite3_exec(db, sql.c_str(), callback, nullptr, &zErrMsg);

        if (rc != SQLITE_OK) {
            std::cout << "SQL error: " << std::endl;
            sqlite3_free(zErrMsg);
        } else {
            std::cout << "Eliminado correctamente" <<  std::endl;
        }
    } else {
        std::cout << "El jugador numero " + std::to_string(numero)
        + " no existe"  <<  std::endl;
    }
}

void showPlayers(sqlite3 *db, char *zErrMsg) {
    std::string sql;
    int rc;

    sql = "SELECT * FROM jugadores;";

    rc = sqlite3_exec(db, sql.c_str(), callback, nullptr, &zErrMsg);

    if (rc != SQLITE_OK) {
        std::cout << "SQL error: " << zErrMsg << std::endl;
        sqlite3_free(zErrMsg);
    } else {
        std::cout << "Mostrado correctamente" << std::endl;
    }
}

void createTableDB(sqlite3 *db, char *zErrMsg) {
    int rc;
    std::string sql;


    sql = "CREATE TABLE IF NOT EXISTS jugadores ("  \
      "ID INTEGER PRIMARY KEY," \
      "NOMBRE         TEXT    NOT NULL," \
      "EDAD           INT     NOT NULL," \
      "NUMERO         INT     NOT NULL," \
      "POSICION       TEXT );";

    rc = sqlite3_exec(db, sql.c_str(), callback, nullptr, &zErrMsg);

    if (rc != 0) {
        std::cout << "SQL error: " << zErrMsg << std::endl;
        sqlite3_free(zErrMsg);
    } else {
        std::cout << "Tabla creada satisfactoriamente" << std::endl;
    }
}

int main(int argc, char* argv[]) {
    sqlite3 *db;
    bool bandera = false;
    char *zErrMsg = nullptr, tecla;
    int rc;

    rc = sqlite3_open("equipo.db", &db);
    if (rc) {
        std::cout << "No se puede abrir la base de datos: %s" << std::endl;
        sqlite3_free(zErrMsg);
    } else {
        std::cout << "Base de datos abierta correctamente" << std::endl;
    }

    createTableDB(db, zErrMsg);

    do {
        std::cin.clear();

        std::cout << std::endl;
        std::cout << "BD Basket" << std::endl;
        std::cout << "-----------" << std::endl << std::endl;
        std::cout << "\t1 .- Añadir jugador" << std::endl;
        std::cout << "\t2 .- Eliminar jugador" << std::endl;
        std::cout << "\t3 .- Mostrar jugadores" << std::endl;
        std::cout << "\t4 .- Salir" << std::endl << std::endl;
        std::cout << "Elije una opción: ";
        std::cin >> tecla;

        switch (tecla) {
            case '1':
                std::system("clear");
                std::cout << "Añadir.\n";
                addPlayer(db, zErrMsg);
                break;

            case '2':
                std::system("clear");
                std::cout << "Eliminar.\n";
                deletePlayer(db, zErrMsg);
                break;

            case '3':
                showPlayers(db, zErrMsg);
                break;

            case '4':
                bandera = true;
                break;

            default:
                std::cout << "Opción no valida.\a\n";
                break;
        }
    } while (!bandera);
    sqlite3_close(db);

    return 0;
}
