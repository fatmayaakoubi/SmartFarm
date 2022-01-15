#include <gtk/gtk.h>


void
on_buttonAcceuil_clicked               (GtkButton       *button,
                                        gpointer         user_data);

void
on_buttonDeconnexin_clicked            (GtkButton       *button,
                                        gpointer         user_data);

void
on_buttonAjoutCapteur_clicked          (GtkButton       *button,
                                        gpointer         user_data);

void
on_buttonListeCapteurs_clicked         (GtkButton       *button,
                                        gpointer         user_data);

void
on_buttonSupprimeCapteur_clicked       (GtkButton       *button,
                                        gpointer         user_data);

void
on_buttonModifCapteur_clicked          (GtkButton       *button,
                                        gpointer         user_data);

void
on_buttonAjouter_clicked               (GtkButton       *button,
                                        gpointer         user_data);

void
on_buttonDeconnexion_clicked           (GtkButton       *button,
                                        gpointer         user_data);

void
on_checkbuttonTemperature_toggled      (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_checkbuttonHumudite_toggled         (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_buttonRechercher_clicked            (GtkButton       *button,
                                        gpointer         user_data);

void
on_buttonModif_clicked                 (GtkButton       *button,
                                        gpointer         user_data);

void
on_buttonSupprimer_activate            (GtkButton       *button,
                                        gpointer         user_data);

void
on_buttonConfirmerModif_clicked        (GtkButton       *button,
                                        gpointer         user_data);

void
on_buttonSupprimer_activate            (GtkButton       *button,
                                        gpointer         user_data);

void
on_buttonSupprimer_clicked             (GtkButton       *button,
                                        gpointer         user_data);

void
on_button19_clicked                    (GtkButton       *button,
                                        gpointer         user_data);

void
on_scrolledwindow1_move_focus_out      (GtkScrolledWindow *scrolledwindow,
                                        GtkDirectionType  direction,
                                        gpointer         user_data);

void
on_actualiser_clicked                  (GtkButton       *button,
                                        gpointer         user_data);

void
on_okbutton1_clicked                   (GtkButton       *button,
                                        gpointer         user_data);

void
on_okbutton2_clicked                   (GtkButton       *button,
                                        gpointer         user_data);

void
on_okbutton3_clicked                   (GtkButton       *button,
                                        gpointer         user_data);

void
on_okbutton4_clicked                   (GtkButton       *button,
                                        gpointer         user_data);

void
on_buttonRechercherS_clicked           (GtkButton       *button,
                                        gpointer         user_data);

void
on_RechSupp_clicked                    (GtkButton       *button,
                                        gpointer         user_data);

void
on_consulter1_clicked                  (GtkButton       *button,
                                        gpointer         user_data);

void
on_button22_clicked                    (GtkButton       *button,
                                        gpointer         user_data);

gboolean
on_treeview_start_interactive_search   (GtkTreeView     *treeview,
                                        gpointer         user_data);

void
on_buttonMarque_clicked                (GtkButton       *button,
                                        gpointer         user_data);
