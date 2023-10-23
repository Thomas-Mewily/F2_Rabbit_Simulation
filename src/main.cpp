#include "__base__.hpp"

#define mois_par_an 12
#define majorite_sexuel 8
#define duree_vie_max (15*mois_par_an)

#define portee_max_simule_par_mois            100000
#define nb_porte_max_simule_par_an_et_par_age 100000
#define max_survie_simule_par_mois            100000

f32 taux_de_survie(int mois)
{
    if(mois < majorite_sexuel){ return 0.35f; }
    if(mois <= 10 * mois_par_an){ return 0.60f; }

    float proba_survie = 0.60f - 0.1* mois/mois_par_an;
    return proba_survie < 0 ? 0 /* hope that life was good for you budy*/ : proba_survie; 
}
struct rabbits
{
    int annee;

    #define max_nb_couple duree_vie_max
    umax nb_couple[duree_vie_max];

    #define max_nb_porte_par_mois mois_par_an
    umax nb_porte_ce_mois[mois_par_an];
};

rabbits initialiser_lapins(int nb_adult_couple)
{
    rabbits r;
    r.annee = 0;

    repeat(i, max_nb_couple) { r.nb_couple[i] = 0; }
    repeat(i, max_nb_porte_par_mois) { r.nb_porte_ce_mois[i] = 0; }

    r.nb_couple[majorite_sexuel] += nb_adult_couple;
    return r;
}

umax nombre_couple(rabbits* r)
{
    umax s = 0;
    repeat(i, max_nb_couple)
    {
        s +=  r->nb_couple[i];
    }
    return s;
}

// Tout les lapins vieillissent d'un mois
void vieillir_un_mois(rabbits* r)
{
    repeat_reverse(mois, max_nb_couple-1)
    {
        r->nb_couple[mois+1] = r->nb_couple[mois];
    }
    r->nb_couple[0] = 0; // 0 "nouveau" couple de 0 mois
}

void gerer_les_portees(rabbits* r, int mois)
{
    #define portee_min_naissance 3
    #define portee_max_naissance 6

    umax nb_porte_ce_mois = r->nb_porte_ce_mois[mois];
    umax nb_lapin = 0;
    usize max_portee_simule = min<usize>(nb_porte_ce_mois, portee_max_simule_par_mois);

    // simule manuellement chaque porté lorsque le nombre est petit
    repeat(_, max_portee_simule)
    {
        nb_lapin += mt_u32_uniform(portee_min_naissance, portee_max_naissance);
    }

    // lorsque le nombre de porté est grand, le résultat tends vers la moyenne des naissances min/max
    // mais appliquer une proportionnalité est plus pratique pour simuler des écarts de variations
    if(nb_porte_ce_mois > portee_max_simule_par_mois)
    {
        nb_lapin *= (nb_porte_ce_mois/(fmax)portee_max_simule_par_mois);
    }
    
    umax nb_couple = nb_lapin / 2; // 50% boy, 50% girl
    r->nb_couple[0] += nb_couple;
}

void plannifier_les_futurs_portees(rabbits* r)
{
    usize nouvelle_portee = 0;
    for(int i = majorite_sexuel; i < duree_vie_max; i++)
    {
        #define nb_porte_min 4
        #define nb_porte_max 8


        usize nb_couple = r->nb_couple[i];
        usize max_nb_couple_simule = min<usize>(nb_couple, nb_porte_max_simule_par_an_et_par_age);
        usize portee_a_ajouter = 0;

        repeat(j, max_nb_couple_simule)
        {
            // biaisé vers 8
            portee_a_ajouter += mt_u32_uniform(mt_u32_uniform(nb_porte_min, nb_porte_max), nb_porte_max);
        }

        // applique un facteur de proportionnalité pour simuler le reste.
        // C'est plus précis que de faire: 
        // portee_a_ajouter = nb_couple * mt_u32_uniform(mt_u32_uniform(nb_porte_min, nb_porte_max), nb_porte_max);
        if(nb_couple > nb_porte_max_simule_par_an_et_par_age)
        {
            portee_a_ajouter *= (nb_couple/(fmax)nb_porte_max_simule_par_an_et_par_age);
        }

        nouvelle_portee += portee_a_ajouter;
    }

    usize nb_portee_par_mois = nouvelle_portee/mois_par_an;
    repeat(mois, mois_par_an)
    {
        r->nb_porte_ce_mois[mois] = nb_portee_par_mois;
    }

    // réparti le reste des portees dans des mois aléatoires
    repeat(i, nouvelle_portee-nb_portee_par_mois*mois_par_an)
    {
        r->nb_porte_ce_mois[mt_u32() % mois_par_an]++;
    }
}

void appliquer_taux_de_survie_annuel(rabbits* r)
{
    repeat(mois, max_nb_couple)
    {
        umax nb_couple = r->nb_couple[mois];
        f32 taux_survie = taux_de_survie(mois);



        usize max_survie_simule = min<usize>(max_survie_simule_par_mois, nb_couple);
        umax nb_couple_vivant = 0;

        repeat(i, max_survie_simule)
        {
            nb_couple_vivant += (mt_real() <= taux_survie ? 1 : 0);
        }

        if(nb_couple > max_survie_simule_par_mois)
        {
            nb_couple_vivant *= (nb_couple/(fmax)max_survie_simule_par_mois);
        }
        //nb_couple_vivant = nb_couple * taux_de_survie(mois);
        r->nb_couple[mois] = nb_couple_vivant;
    }
}

void simuler_annee(rabbits* r)
{
    appliquer_taux_de_survie_annuel(r);
    plannifier_les_futurs_portees(r);

    repeat(mois, mois_par_an)
    {
        vieillir_un_mois(r);
        gerer_les_portees(r, mois);
    }

    r->annee++;
}

void simuler_x_annees(rabbits* r, int x)
{
    goto middle; // to make the weird loop
    while(r->annee < x)
    {
        simuler_annee(r);
        middle:
        printf("année %2i, %-32" umax_format " couples de lapins\n", r->annee, nombre_couple(r));
    }
}

int main(int argc, char const* argv[])
{
    unused(argc);
    unused(argv);

    only_in_debug(printf("%sCompiled%s at %s \n", COLOR_DEBUG_CATEGORY, COLOR_RESET, current_time));
    only_in_debug(betterCPP_verification());
    print_size(fmax);

    u32 init[4]={0x123, 0x234, 0x345, 0x456}, length=4;
    mt_init_by_array(init, length);

    int max_annee = 20;

    repeat(i, 3)
    {
        rabbits r = initialiser_lapins(5);
        simuler_x_annees(&r, max_annee);
        printf("\n");
    }

    
    only_in_debug(memory_printf_final());
    only_in_release(printf("fin\n"));
    return EXIT_SUCCESS;
}