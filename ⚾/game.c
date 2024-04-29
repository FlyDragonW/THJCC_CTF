#include <stdio.h>
#include <string.h>

void clear_screen() {
    printf("\033[2J\033[H");
    fflush(stdout); 
}

void flag(){
    char enc[] = {0x32, 0x24, 0x33, 0x27, 0x31, 0x1a, 0x12, 0x30, 0x56, 0x03, 0x2c, 0x0d, 0x3b, 0x1f, 0x52, 0x49, 0x41, 0x40, 0x1b, 0x6c};
    int enclen = strlen(enc);
    char key[] = "flydragon";
    int keylen = strlen(key);

    for(int i=0;i < enclen;i++){
        key[i] = key[i % keylen];
        enc[i] = enc[i] ^ key[i];
        printf("%c", enc[i]);
    }
    printf("\n");
}

void draw_progress_bar(int progress, int total) {
    const int bar_width = 50;
    float percentage = (float)progress / total;
    int num_chars = percentage * bar_width;

    printf("Calculating Result [");
    for (int i = 0; i < bar_width; ++i) {
        if (i < num_chars) {
            printf("=");
        } else {
            printf(" ");
        }
    }
    printf("] %.2f%%\r", percentage * 100);
    fflush(stdout);
}

void miss(){
    printf("███╗   ███╗██╗███████╗███████╗\n");
    printf("████╗ ████║██║██╔════╝██╔════╝\n");
    printf("██╔████╔██║██║███████╗███████╗\n");
    printf("██║╚██╔╝██║██║╚════██║╚════██║\n");
    printf("██║ ╚═╝ ██║██║███████║███████║\n");
    printf("╚═╝     ╚═╝╚═╝╚══════╝╚══════╝\n");
    printf("Missed!! So u win :> \n");
    flag();
}

void homerun(){
    printf("██╗  ██╗ ██████╗ ███╗   ███╗███████╗    ██████╗ ██╗   ██╗███╗   ██╗\n");
    printf("██║  ██║██╔═══██╗████╗ ████║██╔════╝    ██╔══██╗██║   ██║████╗  ██║\n");
    printf("███████║██║   ██║██╔████╔██║█████╗      ██████╔╝██║   ██║██╔██╗ ██║\n");
    printf("██╔══██║██║   ██║██║╚██╔╝██║██╔══╝      ██╔══██╗██║   ██║██║╚██╗██║\n");
    printf("██║  ██║╚██████╔╝██║ ╚═╝ ██║███████╗    ██║  ██║╚██████╔╝██║ ╚████║\n");
    printf("╚═╝  ╚═╝ ╚═════╝ ╚═╝     ╚═╝╚══════╝    ╚═╝  ╚═╝ ╚═════╝ ╚═╝  ╚═══╝\n");
    printf("\n");
    printf("It's a homerun!! So u lose :( \n");
}

int main() {
    int is_ohtani = 1;
    char opponent[] = "Flydragon OwO";
    
    printf("===== Welcome to the baseball game! =====\n");
    if(is_ohtani)
        strcpy(opponent, "Ohtani Shohei");
    printf("Your opponent is %s !\n", opponent);
    
    getchar();
    clear_screen();

    printf("========== Baseball Court ==========\n\n");
    printf("                 B▭\n");
    printf("                 /  \\\n");
    printf("                /    \\\n");
    printf("               /      \\\n");
    printf("              /   P    \\\n");
    printf("             ▬        ▬\n");
    printf("               ╲  ▬  ╱\n\n");
    printf("========== Baseball Court ==========\n\n");
    int choose = 0;
    printf("Please choose the pitch you want to throw\n");
    printf("(1) Fastball\n");
    printf("(2) Curveball\n");
    printf("(3) Slider\n");
    printf("(4) Changeup\n");
    scanf("%d", &choose);
    
    clear_screen();
    int total_steps = 1000000;
    for (int i = 0; i <= total_steps; ++i) {
        draw_progress_bar(i, total_steps);
    }
    clear_screen();

    if(strcmp(opponent, "Flydragon OuO") == 0 && choose == 0xdeadbeef)
        miss();
    else
        homerun();

    return 0;
}
