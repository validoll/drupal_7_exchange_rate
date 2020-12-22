# Exchange rate

## Введение

Проект тестового задания основанный на Docker4Drupal.

## Состав контейнеров

Проект содержит следующие контейнеры:

| Container       | Versions               | Service name    | Image                              | 
| --------------  | ---------------------- | --------------- | ---------------------------------- |
| [Nginx]         | 1.19                   | `nginx`         | [wodby/nginx]                      | |
| [PHP]           | 7.3                    | `php`           | [wodby/drupal-php]                 |
| Crond           |                        | `crond`         | [wodby/drupal-php]                 |
| [MariaDB]       | 10.5                   | `mariadb`       | [wodby/mariadb]                    |
| [Mailhog]       | latest                 | `mailhog`       | [mailhog/mailhog]                  |
| Adminer         | 4.6                    | `adminer`       | [wodby/adminer]                    |
| Portainer       | latest                 | `portainer`     | [portainer/portainer]              |
| Traefik         | latest                 | `traefik`       | [_/traefik]                        |

### Системные требования

Проект тестировался в хост-сред Ubuntu 20.04 LTS. Необходимо наличие установленного [`docker-compose`](https://docs.docker.com/compose/install/).

## Текст задания

Предлагаем разработать сервис «Курсы валют».

Требования:

* загрузка и хранение курсов валют с сайта ЦБ Рф (https://www.cbr.ru/development/SXML) в ручном и автоматическом режимах;
* отображение курсов валют в табличной форме с постраничным выводом и возможностью сортировки и фильтрации по валюте и дате курса;
* отображение динамики изменения курса в виде графика за указанный пользователем период времени;
* сохранение отчета за период времени в формате json;
* документирование исходного кода (включая описание требований к среде исполнения, инструкции по развертыванию).

Результат должен быть предоставлен в виде git репозитория и размещен в публичном хостинге исходного кода (например, github.com)

## Documentation

### Развертывание

1. Склонируйте репозиторий
   ```bash
   git clone git@github.com:validoll/drupal_7_exchange_rate.git
   ```
2. Перейдите в каталог с репозиторием
   ```bash
   cd drupal_7_exchange_rate
   ```
3. Запустите сборку контейнеров
   ```bash
   make
   ```
3. Запустите сборку проекта
   ```bash
   make composer install && make composer install
   ```
4. После запуска всех контейнеров сервис будет доступен по адресу http://exchange.docker.localhost:8000/

### Учетные данные

Логин: `drupal`
Пароль: `drupal`

### Использование

#### Загрузка и хранение курсов валют

Загрузка списка валют и курса на текущую дату реализована через крон.
Ручная загрузка доступна на странице http://exchange.docker.localhost:8000/admin/settings/exchange_rate_currency.

#### Отображение курсов валют в табличной форме

Таблица с курсом валют реализована через [`Views`](https://www.drupal.org/project/views) и выведена на главную страницу. Доступна по адресу http://exchange.docker.localhost:8000/currency-rate/review.

#### Отображение динамики изменения курса в виде графика

Отображение в виде графика реализовано через [`Charts`](https://www.drupal.org/project/charts). Доступна по адресу http://exchange.docker.localhost:8000/currency-rate/chart.

#### Сохранение отчета в формате json

Реализовано через [`Views Data Export - JSON`](https://www.drupal.org/project/views_data_export_json). Доступно на странице таблицы курсов валют внизу страницы в виде ссылки [`JSON`](http://exchange.docker.localhost:8000/currency-rate/export).
