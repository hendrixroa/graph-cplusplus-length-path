# graph-cplusplus-length-path
Determinacion de longitud de caminos por medio de matrices, en c++ 

Dada una matriz de adyacencia de un Grafo Dirigido y un entero R,
hallar un camino de longitud 1 hasta R entre cada par de vértices del Grafo
dado. IMPORTANTE: solo EL PRIMERO de cada longitud (ya que pueden
haber mas de uno de las misma longitud), con el procedimiento que se
señala mas abajo.

ENTRADA:
La entrada debe ser leída desde el archivo “tarea1.in” o "caso.in" el cual se
encontrará en la carpeta del programa.
La primera línea de entrada será un entero R y N, que representara la
longitud máxima de caminos a encontrar y la cantidad de vértices del grafo
respectivamente.
Seguido de esto, vendrán N líneas que representaran las adyacencias
entre cada par de vértices.
SALIDA:
La salida debe ser escrita en el archivo “<john_doe>.out”.
Inicialmente, deberá contener N líneas de la matriz de alcance final A R (A R es la
multiplicación booleana de R veces A)
