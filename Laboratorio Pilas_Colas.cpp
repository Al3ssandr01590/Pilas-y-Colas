#include <iostream>
#include <stack>
#include <queue>

using namespace std;

struct Tarea {
  string descripcion;
};

void agregarTarea(stack<Tarea>& pila_tareas) {
  string descripcion;
  cout << "Ingrese la descripcion de la tarea: ";
  cin.ignore(); // Ignorar salto de linea
  getline(cin, descripcion);

  Tarea nuevaTarea;
  nuevaTarea.descripcion = descripcion;

  pila_tareas.push(nuevaTarea);
  cout << "Tarea agregada exitosamente." << endl;
}

void completarUltimaTarea(stack<Tarea>& pila_tareas) {
  if (pila_tareas.empty()) {
    cout << "No hay tareas para completar." << endl;
  } else {
    Tarea tareaCompletada = pila_tareas.top();
    pila_tareas.pop();

    cout << "Tarea completada: " << tareaCompletada.descripcion << endl;
  }
}

void atenderTareaMasAntigua(queue<Tarea>& cola_tareas) {
  if (cola_tareas.empty()) {
    cout << "No hay tareas para atender." << endl;
  } else {
    Tarea tareaAtendida = cola_tareas.front();
    cola_tareas.pop();

    cout << "Tarea atendida: " << tareaAtendida.descripcion << endl;
  }
}

void mostrarTodasTareas(stack<Tarea>& pila_tareas, queue<Tarea>& cola_tareas) {
  cout << "Tareas en pila (LIFO):" << endl;
  while (!pila_tareas.empty()) {
    Tarea tarea = pila_tareas.top();
    cout << "- " << tarea.descripcion << endl;
    pila_tareas.pop();
  }

  cout << "\nTareas en cola (FIFO):" << endl;
  while (!cola_tareas.empty()) {
    Tarea tarea = cola_tareas.front();
    cout << "- " << tarea.descripcion << endl;
    cola_tareas.pop();
  }
}

int main() {
  stack<Tarea> pila_tareas;
  queue<Tarea> cola_tareas;

  int opcion;

  do {
    cout << "\nMenu de gestion de tareas:" << endl;
    cout << "1. Agregar tarea" << endl;
    cout << "2. Completar ultima tarea" << endl;
    cout << "3. Atender tarea mas antigua" << endl;
    cout << "4. Mostrar todas las tareas" << endl;
    cout << "5. Salir" << endl;
    cout << "Ingrese una opcion: ";
    cin >> opcion;

    switch (opcion) {
      case 1:
        agregarTarea(pila_tareas);
        break;
      case 2:
        completarUltimaTarea(pila_tareas);
        break;
      case 3:
        atenderTareaMasAntigua(cola_tareas);
        break;
      case 4:
        mostrarTodasTareas(pila_tareas, cola_tareas);
        break;
      case 5:
        cout << "Saliendo del programa..." << endl;
        break;
      default:
        cout << "Opcion invalida. Intente de nuevo." << endl;
    }
  } while (opcion != 5);

  return 0;
}