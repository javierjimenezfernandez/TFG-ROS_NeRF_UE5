# DIGITAL TWIN, TELEMATIC CONTROL AND VR GENERATED BY NERF AND 3DGS IN RESCUE TASKS
<div align="justify">
In the digital era, Digital Twins have emerged as key tools for real-time simulation and control of complex physical environments. This final degree project (TFG) presents an immersive telematic control system that combines digital twins with virtual reality (VR), employing advanced technologies such as Neural Radiance Fields (NeRF)[^1] and 3D Gaussian Splatting (3DGS)[^2]. The research demonstrates the feasibility of integrating these 3D reconstruction methods into rescue operations, providing immersive and detailed visualization of the affected environment, facilitating faster response and reducing risk to rescue teams. The main contributions include the identification of optimal tools for the generation of 3D models compatible with digital twin simulation, the evaluation of robustness and deployment times in realistic scenarios, and the compatibility with the lines of research in simulation and telematic control of the Robotics and Cybernetics Laboratory (ROBCIB) of the CAR ETSII UPM-CSIC. The combination of the tools allows an effective deployment in about an hour and a half, demonstrating its applicability in simulated rescue situations.
</div>

## About this repository
<div align="justify">
In this repository you can find:
- The source code of the nodes and the launcher with the ROS parameters necessary for the communication between the robot and Unreal Engine.
- The complete Unreal Engine 5.2. project used for the development of the investigatin including the plugins with the modifications indicated in the memory.
- The manuals of installation and use of the tools used.
- The compilation of basic ROS concepts and commands necessary for the project.
</div>

## Information available
<div align="justify">
The following YouTube channel is available where they can be found the first tests performed with instant-ngp, the robustness tests of the 3D model generation capability for environments considered difficult and the video demonstration of the deployment of the technology.

YouTube channel: [https://www.youtube.com/@JavierJimenezFernandez-upm](https://www.youtube.com/@JavierJimenezFernandez-upm)
</div>

# GEMELO DIGITAL, CONTROL TELEMÁTICO Y RV GENERADA POR NERF Y 3DGS EN TAREAS DE RESCATE
<div align="justify">
En la era digital, los gemelos digitales (Digital Twins) han surgido como herramientas clave para la simulación y el control en tiempo real de entornos físicos complejos. Este trabajo de fin de grado (TFG) presenta un sistema de control telemático inmersivo que combina gemelos digitales con realidad virtual (RV), empleando tecnologías avanzadas como Neural Radiance Fields (NeRF)[^1] y 3D Gaussian Splatting (3DGS)[^2]. La investigación demuestra la viabilidad de integrar estos métodos de reconstrucción 3D en operaciones de rescate, proporcionando una visualización inmersiva y detallada del entorno afectado, lo que facilita una respuesta más rápida y reduce el riesgo para los equipos de rescate. Las contribuciones principales incluyen la identificación de herramientas óptimas para la generación de modelos 3D compatibles con la simulación de gemelos digitales, la evaluación de la robustez y tiempos de despliegue en escenarios realistas, y la compatibilidad con las líneas de investigación en simulación y control telemático del laboratorio de Robótica y Cibernética (ROBCIB) del CAR ETSII UPM-CSIC. La combinación de las herramientas permite un despliegue efectivo en aproximadamente una hora y media, demostrando su aplicabilidad en situaciones simuladas de rescate.
</div>

## Acerca de este repositorio
<div align="justify">
En este repositorio podrán encontrar:
- El código fuente de los nodos y el launcher con los parámetros de ROS necesarios para la comunicación entre el robot y Unreal Engine.
- El proyecto completo de Unreal Engine 5.2. utilizado para el desarrollo del trabajo incluyendo los plugins con las modificaciones indicadas en la memoria.
- Los manuales de instalación y uso de las herramientas utilizadas.
- La recopilación de conceptos y comandos de ROS básicos necesarios para el proyecto.
</div>

## Información accesible
<div align="justify">
Se pone a disposición el siguiente canal de YouTube donde se pueden encontrar las primeras pruebas llevadas a cabo con instant-ngp, los ensayos de robustez de la capacidad de generación de modelos 3D para entornos considerados difíciles y el vídeo demostrativo del despliegue de la tecnología.

Canal de YouTube: [https://www.youtube.com/@JavierJimenezFernandez-upm](https://www.youtube.com/@JavierJimenezFernandez-upm)

La relación de vídeos que se encuentran en el canal de YouTube es la siguiente:
- instant-ngp - Entrenamiento Flores Amarillas
- Ensayos de robustez de 3DGS - Entornos con elementos repetitivos
- Ensayos de robustez de 3DGS - Objetos de tamaño reducido
- Ensayos de robustez de 3DGS - Elementos con geometrías complejas
- Ensayos de robustez de 3DGS - Escenas con humo o niebla
- Ensayos de robustez de 3DGS - Escenas nocturnas
- Ensayos de robustez de 3DGS - Grabaciones con cámara térmica
- Ensayos de robustez de 3DGS - Escenas con reflejos y refracción
- Demostración del flujo de trabajo completo
</div>

## Descripción general
<div align="justify">
En la era digital, los gemelos digitales (Digital Twins) han emergido como herramientas fundamentales para la simulación y el control en tiempo real de entornos fíısicos complejos. Este trabajo presenta el desarrollo de un sistema de control telemático inmersivo que combina la tecnología de los gemelos digitales con realidad virtual (VR), generada a partir de Neural Radiance Fields (NeRF)[^1] y posteriores desarrollos derivados de este como 3D Gaussian Splatting (3DGS)[^2].

Para ilustrar el punto de partida se presentan en la figura 0.1 un escenario típico de entrenamiento de Digital Twins (0.1a) y el estado del arte en teleoperación de sistemas robótico con interfaces de realidad virtual en el laboratorio de Robótica y Cibernética (ROBCIB) del CAR ETSII - UPM (0.1b); y en la figura 0.2 ejemplos de modelos 3D de entornos físicos complejos en los que se propone desplegar dichos gemelos digitales.

</div>
<div align="center">

<img height="150" alt="Ejemplo (a) de Digital Twins en entornos artificiales o poco realistas" src="https://github.com/user-attachments/assets/751acb4a-73df-4233-9bd6-b63de7f39f2c" >
<img height="150" alt="Ejemplo (b) de Digital Twins en entornos artificiales o poco realistas" src="https://github.com/user-attachments/assets/f53dd621-1235-438d-bf9e-e698f8c36276" >

> Figuras 0.1a y 0.1b. Ejemplos de Digital Twins en entornos artificiales o poco realistas. _Fuentes:_ [^3] y [^4].

<img height="300" alt="Ejemplos de modelos 3D de entornos complejos generados con 3DGS" src="https://github.com/user-attachments/assets/8b7f329f-a1af-4639-8341-a7336d56de95" >

> Figura 0.2: Ejemplos de modelos 3D de entornos complejos generados con 3DGS. _Fuente:_ [^2]

</div>
<div align="justify">

Esta investigación busca demostrar que es posible la integración de estas tecnologías de reconstrucción de modelos 3D con las operaciones de rescate en situaciones de emergencia, proporcionando a los operadores una visualización inmersiva y detallada del entorno afectado.

La reconstrucción precisa y realista de entornos tridimensionales a partir de imágenes bidimensionales en la que puedan operar los gemelos digitales de los robots desplegados también permite la simulación de posibles escenarios de catástrofe.

De esta forma no solo se facilita una respuesta más rápida y efectiva, sino que también reduce el riesgo para los equipos de rescate.

Las principales aportaciones de este proyecto son las siguientes:
1. La combinación de herramientas óptima para la obtención de un modelo 3D compatible con la simulación de los gemelos digitales de los robots.
2. La robustez y el tiempo de despliegue de la tecnología en situaciones de aplicación realistas.
3. La compatibilidad con las líneas de investigación actuales del laboratorio de Robótica y Cibernética (ROBCIB) del CAR ETSII UPM-CSIC en particular la simulación y el control telemático de robots mediante el uso de la realidad virtual para una colaboración más estrecha y segura entre operadores y robots.

La combinación de las herramientas utilizadas en este proyecto permite el despliegue de la tecnología en un tiempo aproximado de una hora y media para una situación simulada de rescate.

Tras descartar instant-ngp[^5] y Unity por incompatibilidades, se han escogido las herramientas recopiladas en la lista mostrada a continuación. En la figura 0.3 se muestra el diagrama del flujo de trabajo completo de dichas herramientas y, después, la tabla 0.1 recoje los tiempos empleados para su despliegue.

-	FFmpeg[^6], para el preprocesamiento, y COLMAP[^7] con la adiciónn de hloc[^8], para la obtención de la fotogrametría.
-	Splatfacto[^9] (método del entorno de NerfStudio[^9] para 3DGS[^2]) y volinga-model[^10], para la generación del modelo 3D de la escena.
-	Volinga Suite[^10], para compatibilidad con Unreal Engine (UE).
-	UE junto con el plugin de Volinga[^10], para su representación en un entorno de realidad virtual compatible con la simulación de los gemelos digitales de los robots.
-	Rosbridge[^11] y ROSIntegration[^12], para la compatibilidad con las líneas actuales de investigación que usan el estándar de ROS.

</div>
<div align="center">

<img alt="Flujo de trabajo completo" src="https://github.com/user-attachments/assets/7f7ed627-fc66-483e-a8ea-2afcc8328fd5" >

> Figura 0.3: Flujo de trabajo completo. _Fuente: elaboración propia_

<img height="300" alt="Tabla de tiempos de despliegue del flujo de trabajo completo" src="https://github.com/user-attachments/assets/b4998254-9a7f-4310-8a9f-b1108d60f0b7" >

> Tabla 0.1: Tabla de tiempos de despliegue del flujo de trabajo completo. _Fuente: elaboración propia_

</div>
<div align="justify">

Con todo ello, el aspecto de la tecnología desplegada durante la demostración se puede observar en las imágenes de la figura 0.4.

</div>
<div align="center">

<img alt="Demostración del flujo de trabajo completo" src="https://github.com/user-attachments/assets/4ff0cf6a-3136-4187-ab96-527165159d97" >

> Figura 0.4: Demostración del flujo de trabajo completo. _Fuente: elaboración propia_

</div>

## Palabras clave
<div align="justify">
Digital Twin, control telemático, simulación inmersiva, NeRF, Gaussian Splatting, Unreal Engine, realidad virtual para rescates.
</div>

## Referencias
[^1]: Mildenhall, B. et al. (2020). _NeRF: Representing Scenes as Neural Radiance Fields for View Synthesis_. En: _ECCV 2020 Oral_. url: [https://www.matthewtancik.com/nerf](https://www.matthewtancik.com/nerf)
[^2]: Kerbl, B., Kopanas, G., Leimk¨uhler, T. y Drettakis, G. (jul. de 2023). _3D Gaussian Splatting for Real-Time Radiance Field Rendering_. En: _ACM Transactions on Graphics 42.4_. url: [https://repo-sam.inria.fr/fungraph/3d-gaussian-splatting/](https://repo-sam.inria.fr/fungraph/3d-gaussian-splatting/).
[^3]: Rudin, N., Hoeller, D., Reist, P. y Hutter, M. (2021). _Learning to Walk in Minutes Using Massively Parallel Deep Reinforcement Learning_. En: _ArXiv abs/2109.11978_. url: [https://api.semanticscholar.org/CorpusID:237635100](https://api.semanticscholar.org/CorpusID:237635100).
[^4]: Cruz Ulloa, C. (mar. de 2024). _Quadrupedal Robots in Search and Rescue: Perception and Teleoperation_. doi: 10.20868/UPM.thesis.81769. url: [https://oa.upm.es/81769/](https://oa.upm.es/81769/).
[^5]: Müller, T., Evans, A., Schied, C. y Keller, A. (jul. de 2022). _Instant Neural Graphics Primitives with a Multiresolution Hash Encoding_. En: _ACM Trans. Graph. 41.4_, 102:1-102:15. doi: 10.1145/3528223.3530127. url: [https://doi.org/10.1145/3528223.3530127](https://doi.org/10.1145/3528223.3530127) y [https://nvlabs.github.io/instant-ngp/](https://nvlabs.github.io/instant-ngp/).
[^6]: Tomar, S. (2006). _Converting video formats with FFmpeg_. En: _Linux Journal 2006.146, pág. 10_. url: [https://www.ffmpeg.org/](https://www.ffmpeg.org/)
_FFmpeg_
[^7]: Schönberger, J. L., Zheng, E., Pollefeys, M. y Frahm, J.-M. (2016). _Pixelwise View Selection for Unstructured Multi-View Stereo_. En: _European Conference on Computer Vision (ECCV)_. url: [https://colmap.github.io/](https://colmap.github.io/)
[^8]: Sarlin, P.-E., Cadena, C., Siegwart, R. y Dymczyk, M. (2019). _From Coarse to Fine: Robust Hierarchical Localization at Large Scale_. En: _CVPR_. url: [https://github.com/cvg/Hierarchical-Localization](https://github.com/cvg/Hierarchical-Localization)
[^9]: Tancik, M. et al. (2023). _Nerfstudio: A Modular Framework for Neural Radiance Field Development_. En: _ACM SIGGRAPH 2023 Conference Proceedings. SIGGRAPH ’23_. url: [https://docs.nerf.studio/](https://docs.nerf.studio/)
[^10]: Volinga development team (2023). _Volinga Suite, volinga-model and Volinga plugin_. url: [https://volinga.ai/](https://volinga.ai/) y [https://github.com/Volinga/volinga-model](https://github.com/Volinga/volinga-model)
_Volinga_
[^11]: Crick, C., Jay, G., Osentoski, S., Pitzer, B. y Jenkins, O. C. (2011). _ROSbridge: ROS for Non-ROS Users_. En: _Proceedings of the Robotics Systems Science and Systems Conference (RSS)_. url: [http://rosbridge.org](http://rosbridge.org).
[^12]: Schmeisser, M. y Suero, M. (2018). _ROSIntegration: Connecting Unreal Engine with ROS for Realistic Simulations_. En: _Proceedings of the IEEE/RSJ International Conference on Intelligent Robots and Systems (IROS)_. url: [https://github.com/code-iai/ROSIntegration](https://github.com/code-iai/ROSIntegration).
_ROSIntegration_
