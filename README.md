# cese_testing_de_software_en_sistemas_embebidos


En el directorio TP_3 se encuentran dos subdirectorios
- componente
- esp32-integracion

El primero es el componente agnostico 'measuring-services' que orquesta las invocaciones a las bibliotecas dht.h y bmp280.h para poder realizar lecturas de presion y temperatura. Este directorio ademas incluye los tests cases realizados con CMock, Ceedling y Unity. Para poder ejecutar los tests cases de este componente solo basta con ejecutar el comando 'ceedling' dentro del directorio 'measuring-services'.

El segundo directorio 'esp32-integracion' consta de la aplicacion real ESP-IDF que utilizando FreeRTOS invoca al componente 'measuring-services' para poder orquestar las lecturas. En el directorio 'esp32-integracion/test' se encuentran los mismos tests cases mencionados arriba. Para poder ejecutar los tests cases y lanzar el proceso de building del componente solo basta con ejecutar el comando 'docker-compose up' desde el directorio 'esp32-integracion'. Tener en cuenta que es un proyecto Docker por lo cual se requiere tener instalado Docker y docker-compose, asi como el servicio de Docker corriendo. 
Nota: las ejecuciones de docker crean el directorio build con permisos de usuario root (debido al uid del proceso virtualizado) por lo cual para borrar el directorio desde el sistema host se requieren permisos de super usuario.