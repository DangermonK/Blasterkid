// AppManager.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.
//

#include <iostream>
#include "StateMaschine.h"
#include "GameState.h"

#include <SFML/Graphics.hpp>

class SFMLAdapter : public DisplayAdapter {

private:
    sf::RenderWindow frame;
    sf::Event evnt;

    sf::Font font;
    sf::RectangleShape rect;

public:
    SFMLAdapter() {
        frame.create(sf::VideoMode(800, 600), "Blasterkid");
        font.loadFromFile("arial.ttf");
    }
    ~SFMLAdapter() {}

    virtual void ClearDisplay() override
    {
        if (frame.pollEvent(evnt)) {
            switch (evnt.type)
            {

            default:
                break;
            }
        }

        frame.clear();
    }
    virtual void DrawText(const std::string& text) override
    {
        sf::Text txt;
        txt.setFillColor(sf::Color::White);
        txt.setFont(font);
        txt.setCharacterSize(36);
        txt.setString(text);
        txt.setPosition(sf::Vector2f(20, 20));
        frame.draw(txt);
    }

    virtual void Display() override
    {
        frame.display();
    }

    virtual void DrawRect(const float& x, const float& y, const float& w, const float& h) override
    {
        rect.setPosition(x, y);
        rect.setSize(sf::Vector2f(w, h));
        frame.draw(rect);
    }
};

int main()
{

    StateMaschine sm(new SFMLAdapter());

    sm.AddState<GameState>(StateType::GAME_STATE);

    sm.SetState(StateType::GAME_STATE);

    sf::Clock clock;
    float lastTime = 0;           

    while (true) {
        float currentTime = clock.getElapsedTime().asSeconds();
        float fps = 1.f / (currentTime - lastTime);
        lastTime = currentTime;
        std::cout << fps << std::endl;
        sm.UpdateState();
        sm.RenderState();
    }

    return 0;

}

// Programm ausführen: STRG+F5 oder Menüeintrag "Debuggen" > "Starten ohne Debuggen starten"
// Programm debuggen: F5 oder "Debuggen" > Menü "Debuggen starten"

// Tipps für den Einstieg: 
//   1. Verwenden Sie das Projektmappen-Explorer-Fenster zum Hinzufügen/Verwalten von Dateien.
//   2. Verwenden Sie das Team Explorer-Fenster zum Herstellen einer Verbindung mit der Quellcodeverwaltung.
//   3. Verwenden Sie das Ausgabefenster, um die Buildausgabe und andere Nachrichten anzuzeigen.
//   4. Verwenden Sie das Fenster "Fehlerliste", um Fehler anzuzeigen.
//   5. Wechseln Sie zu "Projekt" > "Neues Element hinzufügen", um neue Codedateien zu erstellen, bzw. zu "Projekt" > "Vorhandenes Element hinzufügen", um dem Projekt vorhandene Codedateien hinzuzufügen.
//   6. Um dieses Projekt später erneut zu öffnen, wechseln Sie zu "Datei" > "Öffnen" > "Projekt", und wählen Sie die SLN-Datei aus.
