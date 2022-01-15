#include <gtk/gtk.h>


void
on_buttonListeEmployes_clicked         (GtkWidget       *button,
                                        gpointer         user_data);

void
on_buttonSupprimeEmploye_clicked       (GtkButton       *button,
                                        gpointer         user_data);

void
on_buttonAcceuil_clicked               (GtkButton       *button,
                                        gpointer         user_data);

void
on_buttonRetour_clicked                (GtkButton       *button,
                                        gpointer         user_data);

void
on_buttonDeconnexion_clicked           (GtkButton       *button,
                                        gpointer         user_data);

void
on_buttonAjoutEmploye_clicked          (GtkButton       *button,
                                        gpointer         user_data);

void
on_buttonModifEmploye_clicked          (GtkButton       *button,
                                        gpointer         user_data);

void
on_buttonAjouter_clicked               (GtkWidget       *button,
                                        gpointer         user_data);

void
on_buttonRechercher_clicked            (GtkButton       *button,
                                        gpointer         user_data);

void
on_buttonSupprimer_clicked             (GtkButton       *button,
                                        gpointer         user_data);

void
on_treeview_row_activated              (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_checkbuttonMale_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_checkbuttonFemelle_toggled          (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_test_clicked                        (GtkButton       *button,
                                        gpointer         user_data);

gboolean
on_treeview_start_interactive_search   (GtkTreeView     *treeview,
                                        gpointer         user_data);

void
on_buttonRefresh_clicked               (GtkButton       *button,
                                        gpointer         user_data);

void
on_buttonModif_clicked                 (GtkButton       *button,
                                        gpointer         user_data);

void
on_buttonConfirmerModif_clicked        (GtkButton       *button,
                                        gpointer         user_data);

void
on_checkbuttonModifierMale_toggled     (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_checkbuttonModifierFemelle_toggled  (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_RechercherSupp_clicked              (GtkButton       *button,
                                        gpointer         user_data);

void
on_buttonPointage_clicked              (GtkButton       *button,
                                        gpointer         user_data);

void
on_buttonCofirmerPointage_clicked      (GtkButton       *button,
                                        gpointer         user_data);

void
on_button1_clicked                     (GtkButton       *button,
                                        gpointer         user_data);

void
on_buttonConsulter_clicked             (GtkButton       *button,
                                        gpointer         user_data);

void
on_buttonChercherTaux_clicked          (GtkButton       *button,
                                        gpointer         user_data);

void
on_buttonRefreshTaux_clicked           (GtkButton       *button,
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
on_okbutton5_clicked                   (GtkButton       *button,
                                        gpointer         user_data);

void
on_okbutton6_clicked                   (GtkButton       *button,
                                        gpointer         user_data);

void
on_buttonGenererPire_clicked           (GtkButton       *button,
                                        gpointer         user_data);
