#include "uiManager.h"

UIManager::UIManager(int ancho, int alto){
    anchoVentana = ancho;
    altoVentana  = alto;
    opcionSeleccionada = -1;

    // Rectangulos fijos para las 4 opciones
    // Dos columnas, dos filas — parte inferior de la pantalla
    int margen  = 40;
    int gap     = 16;
    int btnW    = (anchoVentana - margen*2 - gap) / 2;
    int btnH    = 70;
    int baseY   = altoVentana - 200;

    rectOpciones[0] = {(float)margen,          (float)baseY,        (float)btnW, (float)btnH};
    rectOpciones[1] = {(float)margen + btnW + gap, (float)baseY,    (float)btnW, (float)btnH};
    rectOpciones[2] = {(float)margen,          (float)baseY + btnH + gap, (float)btnW, (float)btnH};
    rectOpciones[3] = {(float)margen + btnW + gap, (float)baseY + btnH + gap, (float)btnW, (float)btnH};
}

void UIManager::cargarFuente(string ruta){
    fuente = LoadFont(ruta.c_str());
}

// Dibuja texto con saltos de línea automáticos
void UIManager::dibujarTextoEnvuelto(string texto, int x, int y, int ancho, int size, Color color){
    int espacioX = x;
    int espacioY = y;
    string palabra = "";

    for(int i = 0; i <= (int)texto.size(); i++){
        char c = (i < (int)texto.size()) ? texto[i] : ' ';

        if(c == ' ' || c == '\n' || i == (int)texto.size()){
            // Medir la palabra
            Vector2 medida = MeasureTextEx(fuente, (palabra + " ").c_str(), size, 1);

            // Si se sale del ancho, saltar línea
            if(espacioX + medida.x > x + ancho || c == '\n'){
                espacioX = x;
                espacioY += size + 6;
            }

            DrawTextEx(fuente, palabra.c_str(), {(float)espacioX, (float)espacioY}, size, 1, color);
            espacioX += medida.x;
            palabra = "";
        } else {
            palabra += c;
        }
    }
}

void UIManager::dibujarEscena(string texto){
    // Fondo
    DrawRectangle(0, 0, anchoVentana, altoVentana, COLOR_FONDO);

    // Línea separadora entre texto y opciones
    int separadorY = altoVentana - 230;
    DrawLine(40, separadorY, anchoVentana - 40, separadorY, COLOR_BORDE);

    // Texto narrativo — zona superior
    dibujarTextoEnvuelto(texto, 50, 60, anchoVentana - 100, 20, COLOR_TEXTO);
}

void UIManager::dibujarOpciones(string opciones[], NodoArista* hArista){
    NodoArista* aux = hArista;
    int i = 0;

    while(aux && i < 4){
        Vector2 mouse = GetMousePosition();
        bool hover = CheckCollisionPointRec(mouse, rectOpciones[i]);

        // Fondo del botón
        Color fondoBtn = hover ? COLOR_OPCION_HOVER : COLOR_OPCION;
        DrawRectangleRounded(rectOpciones[i], 0.15f, 6, fondoBtn);
        DrawRectangleRoundedLines(rectOpciones[i], 0.15f, 6, COLOR_BORDE);

        // Texto de la opción centrado verticalmente
        Vector2 medida = MeasureTextEx(fuente, opciones[i].c_str(), 18, 1);
        float textX = rectOpciones[i].x + (rectOpciones[i].width - medida.x) / 2;
        float textY = rectOpciones[i].y + (rectOpciones[i].height - medida.y) / 2;

        // Texto envuelto si es largo
        dibujarTextoEnvuelto(
            opciones[i],
            (int)rectOpciones[i].x + 12,
            (int)rectOpciones[i].y + 12,
            (int)rectOpciones[i].width - 24,
            17,
            COLOR_TEXTO
        );

        aux = aux->sigArista;
        i++;
    }
}

void UIManager::dibujarBarraDeshonor(float normalizado){
    int barraX = 40;
    int barraY = 20;
    int barraW = anchoVentana - 80;
    int barraH = 14;

    // Etiqueta
    DrawTextEx(fuente, "Deshonor", {(float)barraX, (float)barraY - 18}, 15, 1, COLOR_TEXTO);

    // Fondo
    DrawRectangleRounded({(float)barraX, (float)barraY, (float)barraW, (float)barraH}, 0.5f, 6, COLOR_OPCION);

    // Relleno — verde a rojo según deshonor
    if(normalizado > 0){
        unsigned char r = (unsigned char)(255 * normalizado);
        unsigned char g = (unsigned char)(255 * (1.0f - normalizado));
        Color colorBarra = {r, g, 0, 255};
        DrawRectangleRounded(
            {(float)barraX, (float)barraY, barraW * normalizado, (float)barraH},
            0.5f, 6, colorBarra
        );
    }

    // Borde
    DrawRectangleRoundedLines({(float)barraX, (float)barraY, (float)barraW, (float)barraH}, 0.5f, 6, COLOR_BORDE);
}

int UIManager::obtenerEleccion(){
    if(IsMouseButtonPressed(MOUSE_LEFT_BUTTON)){
        Vector2 mouse = GetMousePosition();
        for(int i = 0; i < 4; i++){
            if(CheckCollisionPointRec(mouse, rectOpciones[i])){
                return i;
            }
        }
    }
    return -1;
}

void UIManager::dibujarPantallaFinal(string mensaje, int deshonor){
    DrawRectangle(0, 0, anchoVentana, altoVentana, COLOR_FONDO);
    dibujarTextoEnvuelto(mensaje, 80, altoVentana/2 - 60, anchoVentana - 160, 24, COLOR_TEXTO);

    string txtDeshonor = "Deshonor final: " + to_string(deshonor);
    DrawTextEx(fuente, txtDeshonor.c_str(), {80, (float)altoVentana/2 + 20}, 20, 1, COLOR_BORDE);
    DrawTextEx(fuente, "Presiona ESC para salir", {80, (float)altoVentana/2 + 60}, 16, 1, COLOR_TEXTO);
}

void UIManager::dibujarPantallaCarga(string mensaje){
    DrawRectangle(0, 0, anchoVentana, altoVentana, COLOR_FONDO);
    DrawTextEx(fuente, mensaje.c_str(), {(float)anchoVentana/2 - 100, (float)altoVentana/2}, 22, 1, COLOR_TEXTO);
}

