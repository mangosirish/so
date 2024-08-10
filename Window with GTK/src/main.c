/**
 * Nombre:    Diego Flores Chávez.
 * Matrícula: 2203031129.
 * Grupo:     CSI01.
 */

#include <gtk/gtk.h>

/**
 * @brief Función de "callback" que se llama cuando la aplicación es activada.
 *
 * Esta función crea una nueva ventana, establece su título y tamaño predeterminado,
 * y agrega un botón con la etiqueta "Diego Flores Chávez" a la ventana. Cuando se
 * hace clic en el botón, se cierra la aplicación.
 *
 * @param app La instancia de GtkApplication.
 * @param user_data Datos adicionales pasados al callback, no utilizados en este caso.
 */
static void activate(GtkApplication *app, gpointer user_data) {
    GtkWidget *window;
    GtkWidget *button;
    GtkCssProvider *css_provider;
    GtkStyleContext *style_context;
    gchar *css;

    // Crear una nueva ventana de aplicación
    window = gtk_application_window_new(app);
    gtk_window_set_title(GTK_WINDOW(window), "CSI01");
    gtk_window_set_default_size(GTK_WINDOW(window), 300, 200);

    // Crear un nuevo botón con la etiqueta "Diego Flores Chávez"
    button = gtk_button_new_with_label("Diego Flores Chávez");

    // Crear un nuevo proveedor de CSS
    css_provider = gtk_css_provider_new();
    css = "button { color: red; }";
    gtk_css_provider_load_from_data(css_provider, css, -1, NULL);

    // Obtener el contexto de estilo del botón y agregar el proveedor de CSS
    style_context = gtk_widget_get_style_context(button);
    gtk_style_context_add_provider(style_context, GTK_STYLE_PROVIDER(css_provider), GTK_STYLE_PROVIDER_PRIORITY_USER);

    // Conectar la señal "clicked" del botón a gtk_widget_destroy para cerrar la ventana
    g_signal_connect_swapped(button, "clicked", G_CALLBACK(gtk_widget_destroy), window);

    // Agregar el botón a la ventana
    gtk_container_add(GTK_CONTAINER(window), button);

    // Mostrar todos los widgets en la ventana
    gtk_widget_show_all(window);

    // Desreferenciar el proveedor de CSS para liberar recursos
    g_object_unref(css_provider);
}

/**
 * @brief Punto de entrada de la aplicación.
 *
 * Esta función crea una instancia de GtkApplication, conecta la señal de activación al
 * callback y ejecuta la aplicación.
 *
 * @param argc Contador de argumentos de la línea de comandos.
 * @param argv Valores de argumentos de la línea de comandos.
 * @return El estado de salida de la aplicación.
 */
int main(int argc, char *argv[]) {
    GtkApplication *app;
    int status;

    // Crear una nueva instancia de GtkApplication
    app = gtk_application_new("com.example.GtkApplication", G_APPLICATION_FLAGS_NONE);
    
    // Conectar la señal "activate" de la aplicación al callback
    g_signal_connect(app, "activate", G_CALLBACK(activate), NULL);

    // Ejecutar la aplicación y almacenar el estado de salida
    status = g_application_run(G_APPLICATION(app), argc, argv);
    
    // Desreferenciar el objeto de la aplicación para liberar recursos
    g_object_unref(app);

    return status;
}