#include <SFML/Audio.hpp>
#include <SFML/Audio/SoundSource.hpp>
#include <SFML/Graphics.hpp>

constexpr sf::Keyboard::Scancode PauseKey = sf::Keyboard::Scancode::Space;
constexpr sf::Keyboard::Scancode ExitKey = sf::Keyboard::Scancode::Escape;

int main() {
  auto window =
      sf::RenderWindow(sf::VideoMode({1920u, 1080u}), "CMake SFML Project");
  window.setFramerateLimit(144);

  sf::Music music("sample.ogg");
  music.play();

  while (window.isOpen()) {
    while (const std::optional event = window.pollEvent()) {
      if (event->is<sf::Event::Closed>()) {
        window.close();
      }
      if (const auto *keyPressed = event->getIf<sf::Event::KeyPressed>()) {
        switch (keyPressed->scancode) {
        case PauseKey:
          if (music.getStatus() == sf::SoundSource::Status::Paused) {
            music.play();
          } else {
            music.pause();
          }
          break;
        case ExitKey:
          window.close();
          break;
        default:
          break;
        }
      }
    }

    window.clear();
    window.display();
  }
}
