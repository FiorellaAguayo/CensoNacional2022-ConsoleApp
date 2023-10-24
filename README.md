# GestionCenso-PrimerParcial-C
Desarrollar en ANSI C:
Se necesita gestionar el Censo Nacional 2022 y para eso se deberá desarrollar lo siguiente:

- ENTIDADES:

- VIVIENDA.
    ● idVivienda (comienza en 20000, autoincremental)
    ● calle (máximo 25 caracteres)
    ● cantidadPersonas
    ● cantidadHabitaciones
    ● tipoVivienda (1.CASA – 2.DEPARTAMENTO – 3.CASILLA - 4.RANCHO)
    ● legajoCensista (debe existir) Validar

- CENSISTA.
    ● legajoCensista
    ● nombre
    ● edad
    ● telefono

- DATOS PREVIOS:
El array de los censistas deberá ser hardcodeado.
Censista ({100, Ana, 34, 1203-2345}, {101, Juan, 24, 4301-54678}, {102, Sol, 47, 5902-37487} )

- MENU DE OPCIONES:
    A. ALTA VIVENDA
    B. MODIFICAR VIVIENDA: Se ingresará el idVivienda, permitiendo en un submenú modificar:
        ● la calle
        ● la cantidad de las personas
        ● la cantidad de habitaciones
        ● el tipo de vivienda
    C. BAJA VIVIENDA: Se ingresará el idVivienda y se realizará una baja lógica.
    D. LISTAR VIVENDAS: Hacer un único listado de todas las viviendas ordenados por calle y ante igualdad
    de calle por cantidad de personas.
    E. LISTAR CENSISTAS
    F. CENSOS REALIZADOS POR CENSISTA
    G. CENSISTA CON MÁS CENSOS
