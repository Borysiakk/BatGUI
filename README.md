# BGUI
The library enables creating a graphical interface in the SFML library

## Init
```
  Gui gui;
  Theme theme("Gui.json");
```

## Example Button
```
void closeEx(sf::RenderWindow & window)
{
  window.close();
}

main()
{
  Button::Ptr button = theme.Create(WidgetType::Button);
  button->connect(TypeSignal::Pressed,std::bind(closeEx,std::ref(window)));
  button->setPosition(70,210);
  button->setSize(sf::Vector2f(250,50));
  button->setText("EXIT");
  
  gui.addWidget(button);
  ...
}
```
![header image](https://github.com/Borysiakk/BatGUI/blob/master/Example/Button.png)
