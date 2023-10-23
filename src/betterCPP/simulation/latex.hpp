#ifndef betterCPP__simulation__latex
#define betterCPP__simulation__latex

#include "__base__.hpp"

void latex_figure_begin(const c_string xlabel, const c_string ylabel);
void latex_figure_end(usize nb_simulations, const c_string titre = "<titre>");

void latex_figure_plot_begin(const c_string color = "blue");
void latex_figure_plot_end();

void latex_text(const c_string txt);



void latex_file_figure_begin(file* f, const c_string xlabel, const c_string ylabel);
void latex_file_figure_end(file* f, usize nb_simulations, const c_string titre = "<titre>");

void latex_file_figure_plot_begin(file* f, const c_string color = "blue");
void latex_file_figure_plot_end(file* f);

void latex_file_text(file* f, const c_string txt);



#endif
