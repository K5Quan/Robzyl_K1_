# Télécharger sur Telegram :
<h2><a href="[https://t.me/k5robby69](https://t.me/k5robby69)">🗲 Telegram </a></h2>

# Documentation Firmware Robzyl K1 V6.12
## Pour Quansheng UV-K1 et UV-K5 (v3)

## 1. Introduction et avertissements

**Robzyl K1** est une évolution du firmware Robzyl pour UV-K5 v1 basée sur **F4HWN Fusion v5.2** permettant la portabilité  vers l'UV-K1. Robzyl apporte des modifications significatives notamment son analyseur de spectre ultra rapide, sous plusieurs modes et avec des fonctionnalités exclusives.

**Compatibilité** : 
- Quansheng UV-K1
- Quansheng UV-K5 (v3 uniquement, avec quelques limitation à préciser)

### ⚠️ Avertissements importants
- **Risque de bricking** : veuillez respecter la compatibilité matérielle
- **Sauvegarde calibration** : impérative avant tout 1er flash de la radio
- **Législation** : Le domaine de la radio est réglementé, chacun est responsable de l’utilisation qu’il fait de sa radio.

## 2. Principaux apports

**Connectivité et Stockage en mémoires**
*   **Support USB et RS232 (Cable Kenwood)**.
-   **Capacité de mémoire** : le firmware propose la gestion de
    + **999 canaux** en mémoire,
    + **20 scanlists**
    + **24 bandes de fréquence**
    + **48 mémoires** en radio FM.

**Analyseur de Spectre et Réception**
*   **Balayage entrelacé** : Utilise des pas (steps) de minimum 25 kHz pour améliorer la détection des signaux lors du scan du spectre.
 - exemple pour 118-136M à 8k33Hz
   - on fait 118.000M + 0 +25k + 50k... 136M
   - puis 118 .00833M + 0 +25k + 50k... 136M
   - puis 118.01666, +0 + 25k + 50k ... 136M
*   **Vitesse de scan** : Capable d'analyser environ **250 canaux par seconde**.
*   **Filtre "Glitch"** : Un nouveau paramètre dans le menu permet d'améliorer la sélectivité en rejetant les parasites.
*   **Squelch Dynamique** : Basé sur la détection de crête, il ignore les variations du bruit de fond pour plus de précision.
*   **Historique défilant** : Une liste d'historique enregistre les fréquences balayées, le nombre de détections et les noms des canaux.
*   **Gestion des modulations** : Sélection automatique de la modulation (FM/AM/SSB) en fonction des informations du canal ou de la bande lors du balayage.
*   **Fréquences à ignorer** : Possibilité de mettre en "blacklist" des fréquences bruyantes pour les sauter lors des prochains scans.

**Modes Spécifiques et Ergonomie**
*   **Affichage simplfié du spectre** : L'affichage par défaut est en histogrammes, mais il est également proposé un écran simplfié [2]
*   **Personnalisation sonore** : Ajout d'une option **Soundboost** et de bips de fin de transmission variés (Mario, Pac-Man, R2D2).

**Retraits** : Pour libérer de l'espace et optimiser les performances, les fonctionnalités **Aircopy** et les **jeux** ont été retirés de cette version.


**Driver CHIRP inclus** : `Chirp_Robzyl_K1.py`

  - Pour bénéficier des 999 canaux, il faut d'abord installer une version USB ou RS232, uploader les mémoires avec Chrip puis revenir en version NO_COM.
 Ce driver permet aussi la personnalisation des 24 bandes sur les canaux de 1000 à 1024.

## 4. Installation et configuration initiale

### 4.1 Prérequis
1. Identifier votre radio : UV-K5 v3 ou UV-K1
2. Télécharger le fichier ROBZYL.K1.STD.bin
3. Accéder à un flasher web type [Multi-UVTools](https://spm81.github.io/Multi-UVTools/) ou [UVTools2](https://armel.github.io/uvtools2/)


### 4.2 Sauvegarde initiale obligatoire !!
Avant toute installation d'un nouveau firmware sur une radio, il est **important** de sauvegarder les données de calibration (Dump calibration sur [Multi-UVTools](https://spm81.github.io/Multi-UVTools/) ou [UVTools2](https://armel.github.io/uvtools2/))


### 4.2 Procédure de flashage
1. Brancher la radio au PC, idéalement en USB pour plus de rapidité.
2. Accéder au flasher web
3. Démarrer en pressant PTT, la radio passe en mode DFU (led blanche allumée fixe)
4. Flasher la radio qui redemarrera en fin de mise à jour.

### 4.3 Configuration CHIRP
1. Télécharger le driver Chirp_Robzyl_K1.py
2. Brancher la radio au PC
3. Exécuter Chrip en mode développeur et à l'aide d'un raccourci du type : "C:\Program Files\CHIRP\chirp.exe" --module C:\CHIRPpy\Chirp_Robzyl_K1.py
4. Télécharger depuis la radio → Modifier les mémoires → Uploader vers la radio

## 5. Guide de référence et menu général

**Guide de base** : Pour les focntionanlités de base du firmware, veuillez vous reporter au [Guide F4HWN Fusion v5.2.0 disponible en PDF](https://www.dropbox.com/scl/fi/tuv1j8r4ct0503lw9qhtb/MENU-ARMEL-F4HWN-K1-Fusion-v5.2.0.pdf?e=3&fbclid=IwY2xjawQav_pleHRuA2FlbQIxMQBicmlkETFSc0VnSTB4OVpOYzlqQWRPc3J0YwZhcHBfaWQQMjIyMDM5MTc4ODIwMDg5MgABHqWft_sOj1NWqHCrYDFH7kIVyxdctXuEwqtkX4SFV2P76sXNUKluA8hkVy20_aem_yY7q7BrxxU69xQ7l3bGSrw&rlkey=ua3qqsvqarnozp5be0ul9i2f3&dl=0)

**Menu principal**  accessible en mode MR/VFO :

| Pas de menu | Fonction | 
|-------------|----------|
| **1-18** | Paramètres par canal |
| **19-74** | Paramètres système | 

Se référer au guide pour les détaisl concernant chaque pas de menu.

## 6. Raccourcis clavier

| Touche | Court | Long | F+ |
|--------|-------|------|----|
| **MENU** | Menu | - | - |
| **EXIT** | Quitte | - | - |
| **< >** |Touches ↑↓ | - |Squelch ↑↓|
| **1** | - | Plan de bande | Plan de bande |
| **2** | - | VFO A/B | - |
| **3** | - | VFO/MR | - |
| **4** | - | Copie de fréquence | Copie de fréquence |
| **5** | - | **Spectre Robzyl** | - |
| **6** | - | Puissance ↑↓ | Puissance ↑↓ |
| **7** | - | VOX N/A | - |
| **8** | Freq inverse | Rétroéclairage BLMax / BLMin | - |
| **9** | -  | Canal favori | Rétroéclairage BLMax / BLMin |
| **\*** | - | Scan VFO/MR * |  Scan CTCSS/DCS  |
| **F** | Fonction | Verrou clavier | - |

 \* Bien que le scan ici soit conservéi, il est **beaucoup plus interessant** de scanner avec l'analyseur de spectre Robzyl (Fn+5) qui est ultra performant.
 
## 7. Spectre / Bandscope Robzyl

### 7.1 Avantages vs F4HWN
✅ Remplacement COMPLET du spectre F4HWN
✅ Multiples modes avancés : BANDE, SCAN-LISTE, RANGE, FREQUENCE 
✅ 24 Bandes personnalisables. Une bande définit un fréquence de start, stop, une modulation et un step.
✅ Précis, rapide et fluide

| Mode | Description |
|---------|-------------|
| **BANDE** | 24 bandes configurables|
| **SCAN-LIST** | 20 scan-listes basées sur vos canaux mémoire |
| **RANGE** | Spectre sur bornes de fréquence début / fin |
| **FREQUENCE** | Spectre centrée sur la fréquence en VFO |

### 7.2 Utilisation pratique

**Lancement du spectre** : Fn+5 depuis le VFO.

<img width="512" height="320" alt="0-robzyl-main" src="https://github.com/user-attachments/assets/f28463e6-5542-4c1d-ace4-b2ab3a44c4ac" />

* Ligne supérieure : DSxx valeur de DynamicSquel, Modulation, largeur de bande d'écoute, step de canalisation (ou A+XXXX en écoute, valeur AFC)
* Ligne 2-2 : Affichage fréquence en cours et selon le mode la scan-list ou la bande 
* Ligne basse : Étendue en cours et pic de fréquence au centre.

**Affectation des touches :**

|Touche | Fonction | 
|---------------------|---------------|
| **1** | Active le retro éclairage
| **2** | Accès à l’écran simplifié (scanner)
| **3** | Sélection de la largeur de bande d’écoute
| **4** | Menu de séléction mono ou multiple SL ou BD
| **5** | Accès aux Paramètres, puis 1/4 pour naviguer, </> pour changer les valeurs
| **6** | Navigation dans les modes BANDE, SCAN-LISTE, RANGE, FREQUENCE
| **7** | Sauvegarde des principaux paramètres
| **8** | Options d'affichage fréquence BIG/CLASSQIUE
| **9** | Séléction de la modulation
| **0** | Accès à l'historique des récéptions
| **M** | Passage en Still mode (monitoring et accès registres)
| **PTT** | Passer une fréquence à l’écoute (« skip »)
| **SIDE KEY 1** | Passer du mode Normal à FL (verrouillage de fréquence), puis à M (Monitor = écoute ouverte).
| **SIDE KEY 2** | Blacklister une fréquence à l’écoute.
| ***/F** | Réglage squelch dynamqiue Uxx
| **< >** | Naviguation dans les SL, les bandes, ou en fréquence.

**Menu des paramètres :**

<img width="512" height="320" alt="1-robzyl-menu" src="https://github.com/user-attachments/assets/be9c4ea0-72ca-4fc9-85d7-323c3553bb9f" />

* RSSI Delay : temps de capture du RSSI en ms. 
* SpectrumDelay : Permet de définir le temps d’attente sur un signal à l’écoute ayant chuté sous le squelch. Si la valeur est à l’infini : pressez la touche Exit pour quitter l’écran d’écoute.
* Max Listen Time : temps maximum d'écoute d'une fréquence reçue.
* Fstart/Fstop : paramétrage des fréquences ^/v (mode RG).
* Step : paramétrage de la canalisation des fréquences.
* ListenBW : paramétrage de la largeur de la bande d’écoute.
* Modulation : FM/AM/USB.
* RX_Backlight_ON : permet d'activer le rétroéclairage en réception spectre.
* PowerSave : permet d'augmenter le délai de réactualisation du spectre sur l'écran LCD.
* Noislvl_OFF : permet d'ajuster le niveau de bruit à prendre en compte pour éviter des déclenchements d'écoutes intempestifs.
* Popups : règle le délai d'affichage des messages en surimpression.
* Record  Trig : pour enregistrer l'historique en Dynamic Squelch OFF.
* Key Unlocked : verouillage automatique du clavier.
* GlitchMax : niveau de rejet du bruit.
* SoundBoostON : augmente le niveau sonore mais également le risque de distortion.
* Clear History : efface l'historique de l'EEPROM.
* Reset Default : réinitialise les paramètres du spectre ainsi que les registres.

**Vue simplifiée :**

<img width="512" height="320" alt="2-robzyl-simplif" src="https://github.com/user-attachments/assets/3594c6c6-728a-4ffc-88ac-5495ab352456" />

Cet écran offre une vue synthétique du scan en cours. On affiche
  - la Température ambiante (approximative)
  - Le niveau de signal RSSI S:
  - La fréquence
  - Le nom de canal ou bande

**Still mode (monitoring de fréquence) :**

<img width="512" height="320" alt="3-robzyl-still" src="https://github.com/user-attachments/assets/a51c16cc-7d03-49ff-99f2-9cfc6ff8f52b" />

Le still mode se lance avec la touche M sur une fréquence en écoute. Sur cet écran, certains registres sont modifiables pour les utilisateurs avancés.
  - <> permet de changer la fréquence par step
  - */F permet de changer le step

**Historique des fréquences :**

<img width="512" height="320" alt="4-robzyl-histo" src="https://github.com/user-attachments/assets/b0ca73b5-b64a-4b85-bcc2-ee6ffac59bb0" />

L'historique évolue dynamiquement au gré des fréquences reçues. Il est possible de naviguer dans la liste, la radio passe en Frequency Lock (FL) et on peut écouter directement les fréquences stockées (comme une radio FM qui balaie et enregistre des fréquences).

* Touche SK1 : passer en Frequency Lock puis Monitor
* Touches <> : passer en Frequency Lock et se déplacer dans l'historique
* Touche 2 : sauvegarder l'entrée d'historique sélectionnée dans la première mémoire disponible.
* Touche 3 : effacer l'entrée de l'historique.
* Touche 5 : scanner les entrées de l'historique.
* Touche 7 : sauvegarder l'historique en EEPROM.
* Touche 8 : effacer l'historique en mémoire, mais pas en EEPROM.

Il existe un mode spécial de scan en valeur DYN SQUELCH OFF (juste avant la valeur U0). Ce mode permet de collecter très rapidement un historique sans s'arrêter en écoute ; c'est le paramètre Record Trig du menu du spectre qui permet d'ajuster un niveau seuil de déclenchement des signaux à historiser.

## Spectre sur les ScanLists (mode SL)

* Fonction : Permet de charger dans le spectre les mémoires affectées à des scanlists.
* Lancement : Depuis le mode VFO/MR, touche F+5 puis appuyer [6] dans le spectre jusqu'à afficher MODE: S LIST
* Utilisation et conseils :
* Préalablement, les fréquences en mémoires doivent avoir été affectées à une scanlist (ex. SL1 = PMR, SL2 = Répéteurs, SL3 = Aéro, etc.).
* Enfin, chargez vos SL dans le spectre via le menu de sélection en touche 4.

<img width="512" height="320" alt="5-robzyl-sel sl" src="https://github.com/user-attachments/assets/722c1eeb-30ce-4433-9f66-1ccab36be85a" />

On navigue dans ce menu avec les touches ^/v.

* Touche 5 : choisir une SL en excluant les autres.
* Touche 4 : choisir/invalider une ou plusieurs SL.
* Touche * : affichage des mémoires affectées à la SL sélectionnée.

Les SL choisies apparaissent avec un symbole *. Puis faire Exit pour lancer le spectre. Touche 7 pour enregistrer sa configuration.

# Spectre sur plage de fréquences (mode FREQ) :

* Fonction : Permet d’analyser une gamme de fréquences à partir d’une fréquence centrale ou bien à partir d’une étendue définie.
* Lancement : Depuis le mode VFO/MR, touche F+5 puis appuyer [6] dans le spectre jusqu'à afficher MODE: FREQ.
* Utilisation et conseils :
* La fréquence issue du VFO/MR est portée au spectre en tant que fréquence centrale. Ensuite, vous pouvez agir sur le paramétrage de votre spectre selon vos besoins en step, modulation, etc. (Réglages touche 5).
* L’étendue des fréquences basse/haute peut être ajustée dans le menu via les paramètres FStart/FStop. Sur ces paramètres, faire 1 pour accéder à la saisie et M pour valider (touche * pour la virgule).
* Ajuster votre squelch.


## Spectre sur les bandes prédéfinies (mode BAND)

* Fonction : Permet d’analyser en spectre des bandes prédéfinies (ex. PMR, CB, AERO, HAM, etc.).
* Lancement : Depuis le mode VFO/MR, touche F+5 puis appuyer [6] dans le spectre jusqu'à afficher MODE: BAND.
* Il est possible de paramétrer 32 bandes.

Ensuite, le menu touche 4 permet de choisir les bandes à analyser de la même manière que le menu en mode SL :

<img width="512" height="320" alt="5-robzyl-sel bd" src="https://github.com/user-attachments/assets/75c924b3-139a-4d04-8fde-337045eba6d0" />

## 9. Configuration des bandes dans Chirp
Il y a une vidéo d'explication sur mon youtube.
Les canaux mémoires 1000 à 1024 accueillent la personnalisation des bandes utilisables dans le spectre. Pour chaque bande il faut définir :

* La fréquence début et la fréquence de fin (en offset)
* Un nom pour la bande
* Une modulation
* Un step de fréquence

<img width="1410" height="578" alt="image" src="https://github.com/user-attachments/assets/dbc68936-3d7a-478b-a290-6e30d5f67f77" />

Veuillez repecter ce modèle.

<h2><a href="[https://www.youtube.com/@robby_69400](https://www.youtube.com/@robby_69400)" rel="nofollow">🗲 Youtube</a></h2>

### 🙏 Many thanks to Zylka, Kolyan, Iggy, Toni, Yves and Francois
