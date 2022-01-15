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

void
on_etateq_clicked                      (GtkButton       *button,
                                        gpointer         user_data);

void
on_list_clicked                        (GtkWidget       *button,
                                        gpointer         user_data);

void
on_modif_clicked                       (GtkButton       *button,
                                        gpointer         user_data);

void
on_supp_clicked                        (GtkButton       *button,
                                        gpointer         user_data);

void
on_ajout_clicked                       (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_format_clicked                      (GtkButton       *button,
                                        gpointer         user_data);

void
on_deco_clicked                        (GtkButton       *button,
                                        gpointer         user_data);

void
on_acceuil_clicked                     (GtkButton       *button,
                                        gpointer         user_data);

void
on_ajouteq_clicked                     (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_acc1_clicked                        (GtkButton       *button,
                                        gpointer         user_data);

void
on_treev_row_activated                 (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_mod_clicked                         (GtkButton       *button,
                                        gpointer         user_data);

void
on_refrechbut_clicked                  (GtkButton       *button,
                                        gpointer         user_data);

void
on_supbut_clicked                      (GtkButton       *button,
                                        gpointer         user_data);

void
on_chersup_clicked                     (GtkButton       *button,
                                        gpointer         user_data);

void
on_button14_clicked                    (GtkButton       *button,
                                        gpointer         user_data);

void
on_button13_clicked                    (GtkButton       *button,
                                        gpointer         user_data);

void
on_button12_clicked                    (GtkButton       *button,
                                        gpointer         user_data);

void
on_Actualiser_clicked                  (GtkButton       *button,
                                        gpointer         user_data);

void
on_confirm_clicked                     (GtkButton       *button,
                                        gpointer         user_data);

void
on_closebutton1has_clicked             (GtkButton       *button,
                                        gpointer         user_data);

void
on_sauv_clicked                        (GtkButton       *button,
                                        gpointer         user_data);

void
on_Acceuil_clicked                     (GtkButton       *button,
                                        gpointer         user_data);

void
on_stat1_clicked                       (GtkButton       *button,
                                        gpointer         user_data);

void
on_stat2_clicked                       (GtkButton       *button,
                                        gpointer         user_data);

void
on_sure_clicked                        (GtkButton       *button,
                                        gpointer         user_data);

void
on_notsure_clicked                     (GtkButton       *button,
                                        gpointer         user_data);

void
on_succeshas_clicked                   (GtkButton       *button,
                                        gpointer         user_data);

void
on_buttonInterfaceSeif_clicked         (GtkButton       *button,
                                        gpointer         user_data);

void
on_buttonInterfaceHsan_clicked         (GtkButton       *button,
                                        gpointer         user_data);

void
on_sure_clicked                        (GtkButton       *button,
                                        gpointer         user_data);

gboolean
on_imageGestEq_button_press_event      (GtkWidget       *widget,
                                        GdkEventButton  *event,
                                        gpointer         user_data);

gboolean
on_imageGestEq_key_press_event         (GtkWidget       *widget,
                                        GdkEventKey     *event,
                                        gpointer         user_data);

gboolean
on_imageGestEq_button_press_event      (GtkWidget       *widget,
                                        GdkEventButton  *event,
                                        gpointer         user_data);

gboolean
on_eventbox1_button_press_event        (GtkWidget       *widget,
                                        GdkEventButton  *event,
                                        gpointer         user_data);

gboolean
on_eventbox2_button_press_event        (GtkWidget       *widget,
                                        GdkEventButton  *event,
                                        gpointer         user_data);

void
on_AccueilM_clicked                    (GtkButton       *button,
                                        gpointer         user_data);

void
on_Deconnection_clicked                (GtkButton       *button,
                                        gpointer         user_data);

void
on_button1_clicked                     (GtkButton       *button,
                                        gpointer         user_data);

void
on_supprimer_clicked                   (GtkButton       *button,
                                        gpointer         user_data);

void
on_modifier_clicked                    (GtkButton       *button,
                                        gpointer         user_data);

void
on_ajouter_clicked                     (GtkButton       *button,
                                        gpointer         user_data);

void
on_liste_clicked                       (GtkButton       *button,
                                        gpointer         user_data);

void
on_ajouter1_clicked                    (GtkButton       *button,
                                        gpointer         user_data);

void
on_retour1_clicked                     (GtkButton       *button,
                                        gpointer         user_data);

void
on_deconnection1_clicked               (GtkButton       *button,
                                        gpointer         user_data);

void
on_checkbutton2Male_toggled            (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_checkbutton1femelle_toggled         (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_buttonsupre_clicked                 (GtkButton       *button,
                                        gpointer         user_data);

void
on_supprimer1_clicked                  (GtkButton       *button,
                                        gpointer         user_data);

void
on_deconnection3_clicked               (GtkButton       *button,
                                        gpointer         user_data);

void
on_deconnection4_clicked               (GtkButton       *button,
                                        gpointer         user_data);

void
on_retour5_clicked                     (GtkButton       *button,
                                        gpointer         user_data);

void
on_deconnection5_clicked               (GtkButton       *button,
                                        gpointer         user_data);

void
on_confirmer2_clicked                  (GtkButton       *button,
                                        gpointer         user_data);

void
on_accueilM_clicked                    (GtkButton       *button,
                                        gpointer         user_data);

void
on_checkbutton1male_toggled            (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_checkbutton2femelle_toggled         (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_Deconnectionm_clicked               (GtkButton       *button,
                                        gpointer         user_data);

void
on_Accueilmerr_clicked                 (GtkButton       *button,
                                        gpointer         user_data);

void
on_recherchem_clicked                  (GtkButton       *button,
                                        gpointer         user_data);

void
on_Modifierm_clicked                   (GtkButton       *button,
                                        gpointer         user_data);

void
on_button1mar_clicked                  (GtkButton       *button,
                                        gpointer         user_data);

void
on_button2mar_clicked                  (GtkButton       *button,
                                        gpointer         user_data);

void
on_button2RrefreshStat_clicked         (GtkButton       *button,
                                        gpointer         user_data);

void
on_decon_clicked                       (GtkButton       *button,
                                        gpointer         user_data);

void
on_deconn_clicked                      (GtkButton       *button,
                                        gpointer         user_data);

void
on_button3_clicked                     (GtkButton       *button,
                                        gpointer         user_data);

void
on_deconnpro_clicked                   (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_rech_clicked                 (GtkButton       *button,
                                        gpointer         user_data);

void
on_button3mar_clicked                  (GtkButton       *button,
                                        gpointer         user_data);

void
on_button4mar_clicked                  (GtkButton       *button,
                                        gpointer         user_data);

void
on_button5mar_clicked                  (GtkButton       *button,
                                        gpointer         user_data);

void
on_button6mar_clicked                  (GtkButton       *button,
                                        gpointer         user_data);

void
on_AccueilM_clicked                    (GtkButton       *button,
                                        gpointer         user_data);

void
on_AccueilM_clicked                    (GtkButton       *button,
                                        gpointer         user_data);

void
on_buttonCreationCompt_clicked         (GtkButton       *button,
                                        gpointer         user_data);

void
on_buttonLogin_clicked                 (GtkButton       *button,
                                        gpointer         user_data);

gboolean
on_eventbox3_button_press_event        (GtkWidget       *widget,
                                        GdkEventButton  *event,
                                        gpointer         user_data);

gboolean
on_eventbox4_button_press_event        (GtkWidget       *widget,
                                        GdkEventButton  *event,
                                        gpointer         user_data);

void
on_buttonCreationCompt_clicked         (GtkButton       *button,
                                        gpointer         user_data);

void
on_DeconnectionMer_clicked             (GtkButton       *button,
                                        gpointer         user_data);

void
on_buttonAdminModifier_clicked         (GtkButton       *button,
                                        gpointer         user_data);

void
on_buttonAdminRechercher_clicked       (GtkButton       *button,
                                        gpointer         user_data);

void
on_buttonAdminChercherSupp_clicked     (GtkButton       *button,
                                        gpointer         user_data);

void
on_buttonAdminSupp_clicked             (GtkButton       *button,
                                        gpointer         user_data);

void
on_okbutton7_clicked                   (GtkButton       *button,
                                        gpointer         user_data);

void
on_buttonsupprimerg_clicked            (GtkButton       *button,
                                        gpointer         user_data);

void
on_buttonajouter_clicked               (GtkButton       *button,
                                        gpointer         user_data);

void
on_buttonmodifier_clicked              (GtkButton       *button,
                                        gpointer         user_data);

void
on_buttonservices_clicked              (GtkButton       *button,
                                        gpointer         user_data);

void
on_buttonlistclient_clicked            (GtkButton       *button,
                                        gpointer         user_data);

void
on_buttondeconnection_clicked          (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_acceuilgestion_clicked       (GtkButton       *button,
                                        gpointer         user_data);

void
on_checkbuttonhomme_toggled            (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_button_ajouter_clicked              (GtkButton       *button,
                                        gpointer         user_data);

void
on_checkbuttonfemme_toggled            (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_button_afficher_clicked             (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_rechercher_clicked           (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_modifierc_clicked            (GtkButton       *button,
                                        gpointer         user_data);

void
on_buttonacceuil_clicked               (GtkButton       *button,
                                        gpointer         user_data);

void
on_buttonsupprimer_clicked             (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_rechercher_sup_clicked       (GtkButton       *button,
                                        gpointer         user_data);

void
on_buttonAchats_clicked                (GtkButton       *button,
                                        gpointer         user_data);

void
on_buttonlist_achatse_clicked          (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_reservation_clicked          (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_liste_res_clicked            (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_meilleurclient_clicked       (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_actualiser_clicked           (GtkButton       *button,
                                        gpointer         user_data);

void
on_buttonretour_achat_clicked          (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_affichier_achat_clicked      (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_ajouter_achat_clicked        (GtkButton       *button,
                                        gpointer         user_data);

void
on_checkbutton_oui_brebi_toggled       (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_checkbutton_non_brebi_toggled       (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_checkbutton_oui_veau_toggled        (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_checkbutton_non_veau_toggled        (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_checkbutton_oui_yaourt_toggled      (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_checkbutton_non_yaourt_toggled      (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_checkbutton_oui_rigouta_toggled     (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_checkbutton_non_rigouta_toggled     (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton_ouic_toggled            (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton_nonc_toggled            (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_checkbutton_hommemodif_toggled      (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_checkbutton_femmemodif_toggled      (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_button_retour_modif_clicked         (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_modifier_clicked             (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_ok_att_clicked               (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_retour_lista_clicked         (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_affichier_reservation_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_ajouter_reservation_clicked  (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_retour_res_clicked           (GtkButton       *button,
                                        gpointer         user_data);

void
on_buttonretour_listres_clicked        (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_retour_meilleur_clicked      (GtkButton       *button,
                                        gpointer         user_data);

gboolean
on_treeview_rechsup_start_interactive_search
                                        (GtkTreeView     *treeview,
                                        gpointer         user_data);

gboolean
on_eventbox5_button_press_event        (GtkWidget       *widget,
                                        GdkEventButton  *event,
                                        gpointer         user_data);

gboolean
on_eventbox6_button_press_event        (GtkWidget       *widget,
                                        GdkEventButton  *event,
                                        gpointer         user_data);

void
on_Liste_des_Capteur_clicked           (GtkButton       *button,
                                        gpointer         user_data);

void
on_buttonAcceuilCa_clicked             (GtkButton       *button,
                                        gpointer         user_data);

void
on_buttonDeconnexionAmine_clicked      (GtkButton       *button,
                                        gpointer         user_data);

void
on_buttonAjouterCa_clicked             (GtkButton       *button,
                                        gpointer         user_data);

void
on_buttonRechercherCa_clicked          (GtkButton       *button,
                                        gpointer         user_data);

void
on_buttonModifCa_clicked               (GtkButton       *button,
                                        gpointer         user_data);

void
on_buttonSupprimerCa_clicked           (GtkButton       *button,
                                        gpointer         user_data);

void
on_RechSuppCa_clicked                  (GtkButton       *button,
                                        gpointer         user_data);

void
on_actualiserCa_clicked                (GtkButton       *button,
                                        gpointer         user_data);

void
on_okbuttonajout_clicked               (GtkButton       *button,
                                        gpointer         user_data);

void
on_buttonConfirmerModifCa_clicked      (GtkButton       *button,
                                        gpointer         user_data);

void
on_okbuttonmodif_clicked               (GtkButton       *button,
                                        gpointer         user_data);

void
on_okbuttonsupp_clicked                (GtkButton       *button,
                                        gpointer         user_data);

void
on_okbuttonremplir_clicked             (GtkButton       *button,
                                        gpointer         user_data);

void
on_consulterCa_clicked                 (GtkButton       *button,
                                        gpointer         user_data);

void
on_buttonAcceuilCa__clicked            (GtkButton       *button,
                                        gpointer         user_data);

void
on_buttonMarque__clicked               (GtkButton       *button,
                                        gpointer         user_data);

void
on_buttonAjouterCapteur_clicked        (GtkButton       *button,
                                        gpointer         user_data);

void
on_buttonModifCapteur_clicked          (GtkButton       *button,
                                        gpointer         user_data);

void
on_buttonSupprimerCapteur_clicked      (GtkButton       *button,
                                        gpointer         user_data);

void
on_buttonConsulterCapteurs_clicked     (GtkButton       *button,
                                        gpointer         user_data);

void
on_buttonDeconnexinAmine__clicked      (GtkButton       *button,
                                        gpointer         user_data);

void
on_buttonRetourCa_clicked              (GtkButton       *button,
                                        gpointer         user_data);

void
on_checkbuttonTemperature_toggled      (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_checkbuttonHumudite_toggled         (GtkToggleButton *togglebutton,
                                        gpointer         user_data);
