#include "library.h"

typedef struct {
    GtkWidget *window;
    GtkWidget *box;
    GtkWidget *ISBN;
    GtkWidget *bookname;
    GtkWidget *msg_label;
} CallbackData;

void onAddBookSubmit(GtkWidget *widget, gpointer data){
    CallbackData *gdata = (CallbackData *)data;

    const gchar *ISBN = gtk_entry_get_text(GTK_ENTRY(gdata->ISBN));
    const gchar *bookname = gtk_entry_get_text(GTK_ENTRY(gdata->bookname));

    insertBooks((char*)ISBN, (char*)bookname);
    gtk_widget_destroy(GTK_WIDGET(gdata->window));
    g_free(gdata);
}

void onDeleteBookSubmit(GtkWidget *widget, gpointer data){
    CallbackData *gdata = (CallbackData *)data;

    const gchar *ISBN = gtk_entry_get_text(GTK_ENTRY(gdata->ISBN));
    if (searchBook((char*) ISBN) == NULL){
        gchar *message = g_strdup_printf("ISBN does not exist!\n");
        gtk_label_set_text(GTK_LABEL(gdata->msg_label), message);
        gtk_widget_show(gdata->msg_label);
    }else{
        deleteBook((char*)ISBN);
        gtk_widget_destroy(GTK_WIDGET(gdata->window));
        g_free(gdata);
    }
    
}

void onSearchBtn(GtkWidget *widget, gpointer data){
    static int f_count = 0;
    CallbackData *gdata = (CallbackData *)data;

    const gchar *ISBN = gtk_entry_get_text(GTK_ENTRY(gdata->ISBN));
    char* book = searchBook((char*) ISBN);
    if (book == NULL){
        const gchar *text = g_strdup_printf("Book not found!");

         // Create a new label dynamically
        GtkWidget *new_label = gtk_label_new(text);
        
        // Add the label to the box container
        gtk_box_pack_start(GTK_BOX(gdata->box), new_label, FALSE, FALSE, 0);

        // Show the new label
        gtk_widget_show(new_label);

        // Clear entry after submit
        gtk_entry_set_text(GTK_ENTRY(gdata->ISBN), "");
    }else{
        const gchar *text = g_strdup_printf("[Book Found] Book name: %s", book);

         // Create a new label dynamically
        GtkWidget *new_label = gtk_label_new(text);
        
        // Add the label to the box container
        gtk_box_pack_start(GTK_BOX(gdata->box), new_label, FALSE, FALSE, 0);

        // Show the new label
        gtk_widget_show(new_label);
    }
}

void createAddBookWindow(int argc, char* argv[]){
    gtk_init(&argc, &argv);

    // Create main window
    GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "Add book");
    gtk_window_set_default_size(GTK_WINDOW(window), 300, 200);
    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

    // Create a vertical box container
    GtkWidget *vbox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 10);
    gtk_container_set_border_width(GTK_CONTAINER(vbox), 20);

    // Create widgets: labels, entries & button
    GtkWidget *ISBN_label = gtk_label_new("ISBN:");
    gtk_label_set_xalign(GTK_LABEL(ISBN_label), 0.0);
    GtkWidget *ISBN_entry = gtk_entry_new();

    GtkWidget *bookname_label = gtk_label_new("Bookname:");
    gtk_label_set_xalign(GTK_LABEL(bookname_label), 0.0);
    GtkWidget *bookname_entry = gtk_entry_new();
    
    GtkWidget *submit_btn = gtk_button_new_with_label("Submit");

    // Add widgets to the box
    gtk_box_pack_start(GTK_BOX(vbox), ISBN_label, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(vbox), ISBN_entry, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(vbox), bookname_label, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(vbox), bookname_entry, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(vbox), submit_btn, FALSE, FALSE, 10);

    // Add box to the window
    gtk_container_add(GTK_CONTAINER(window), vbox);

    CallbackData *data = g_new(CallbackData, 1); // allocate memory
    data->window = window;
    data->ISBN = ISBN_entry;
    data->bookname = bookname_entry;
    

    // Connect button click to callback
    g_signal_connect(submit_btn, "clicked", G_CALLBACK(onAddBookSubmit), data);

    gtk_widget_show_all(window);
    gtk_main();
}

void createDeleteBookWindow(int argc, char* argv[]){
    gtk_init(&argc, &argv);

    // Create main window
    GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "Delete book");
    gtk_window_set_default_size(GTK_WINDOW(window), 300, 200);
    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

    // Create a vertical box container
    GtkWidget *vbox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 10);
    gtk_container_set_border_width(GTK_CONTAINER(vbox), 20);

    // Create widgets: labels, entries & button

    GtkWidget *ISBN_label = gtk_label_new("ISBN:");
    gtk_label_set_xalign(GTK_LABEL(ISBN_label), 0.0);
    GtkWidget *ISBN_entry = gtk_entry_new();
    GtkWidget *msg_label = gtk_label_new("");
    gtk_widget_hide(msg_label);

    GtkWidget *submit_btn = gtk_button_new_with_label("Submit");

    // Add widgets to the box
    gtk_box_pack_start(GTK_BOX(vbox), ISBN_label, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(vbox), ISBN_entry, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(vbox), msg_label, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(vbox), submit_btn, FALSE, FALSE, 10);

    // Add box to the window
    gtk_container_add(GTK_CONTAINER(window), vbox);

    CallbackData *data = g_new(CallbackData, 1); // allocate memory
    data->window = window;
    data->ISBN = ISBN_entry;
    data->msg_label = msg_label;

    // Connect button click to callback
    g_signal_connect(submit_btn, "clicked", G_CALLBACK(onDeleteBookSubmit), data);

    gtk_widget_show_all(window);
    gtk_widget_hide(msg_label);
    gtk_main();
}

void searchBookWindow(int argc, char* argv[]){
    gtk_init(&argc, &argv);

    // Create main window
    GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "Delete book");
    gtk_window_set_default_size(GTK_WINDOW(window), 300, 200);
    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

    // Create a vertical box container
    GtkWidget *vbox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 10);
    gtk_container_set_border_width(GTK_CONTAINER(vbox), 20);

    // Create widgets: ISBN labels

    GtkWidget *ISBN_label = gtk_label_new("ISBN:");
    gtk_label_set_xalign(GTK_LABEL(ISBN_label), 0.0);
    GtkWidget *ISBN_entry = gtk_entry_new();

    GtkWidget *submit_btn = gtk_button_new_with_label("Submit");

    // Add widgets to the box
    gtk_box_pack_start(GTK_BOX(vbox), ISBN_label, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(vbox), ISBN_entry, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(vbox), submit_btn, FALSE, FALSE, 10);

    // Add box to the window
    gtk_container_add(GTK_CONTAINER(window), vbox);

    CallbackData *data = g_new(CallbackData, 1); // allocate memory
    data->window = window;
    data->ISBN = ISBN_entry;
    data->box = vbox;

    // Connect button click to callback
    g_signal_connect(submit_btn, "clicked", G_CALLBACK(onSearchBtn), data);

    gtk_widget_show_all(window);
    gtk_main();
}