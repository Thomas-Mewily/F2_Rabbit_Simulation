#include "__base__.hpp"


void latex_figure_begin(const c_string xlabel, const c_string ylabel)
{
    latex_file_figure_begin(stdout, xlabel, ylabel);
}
void latex_figure_end(usize nb_simulations, const c_string titre)
{
    latex_file_figure_end(stdout, nb_simulations, titre);
}

void latex_figure_plot_begin(const c_string color)
{
    latex_file_figure_plot_begin(stdout, color);
}
void latex_figure_plot_end()
{
    latex_file_figure_plot_end(stdout);
}

void latex_text(const c_string txt)
{
    latex_file_text(stdout, txt);
}


void latex_file_figure_begin(file* f, const c_string xlabel, const c_string ylabel)
{
    fprintf(f, "\\begin{figure}[H]\n");
    fprintf(f, "\\centering\n");
    fprintf(f, "  \\begin{tikzpicture}");
    fprintf(f, "    \\begin{axis}[\n");
    fprintf(f, "      width=\\linewidth,\n");
    fprintf(f, "      grid=major,\n");
    fprintf(f, "      %%xmin=0,\n");
    fprintf(f, "      %%xmax=100,\n");
    fprintf(f, "      xlabel=");
    latex_file_text(f, xlabel);
    fprintf(f, ",\n");
    fprintf(f, "      ylabel=");
    latex_file_text(f, ylabel);
    fprintf(f, ",\n");
    fprintf(f, "      legend pos=north west,\n");
    fprintf(f, "    ]\n");
}
void latex_file_figure_end(file* f, usize nb_simulations, const c_string titre)
{
    fprintf(f, "    \\end{axis}\n");
    fprintf(f, "  \\end{tikzpicture}\n");
    fprintf(f, "  \\caption{");
    latex_file_text(f, titre);
    fprintf(f, " (%" usize_format" simulations)", nb_simulations);
    fprintf(f, "}\n");
    fprintf(f, "\\end{figure}\n");
}

void latex_file_figure_plot_begin(file* f, const c_string color)
{
    fprintf(f, "      \\addplot[color=%s, mark=+] coordinates{\n", color);
}
void latex_file_figure_plot_end(file* f)
{
    fprintf(f, "      };\n");
}

void latex_file_text(file* f, const c_string txt)
{
    const char* i = txt;
    while(*i != char_eof)
    {
        switch (*i)
        {
            case '%': fprintf(f, "\\%%");  break;
            case '_': fprintf(f, "\\_");   break;
            default: fprintf(f, "%c", *i); break;
        }
        i++;
    }
}