## Bem vindo(a) ao F-BOAT 

## F-BOAT PROJETO

Projeto da UFF desenvolve barco inteligente que monitora as águas na Baía de Guanabara

De acordo com o Instituto Estadual do Meio Ambiente do Rio de Janeiro (INEA-RJ), a crescente pressão sobre os recursos hídricos, além do aumento e da diversidade das fontes de poluição, torna o acompanhamento das alterações da qualidade das águas cada vez mais necessário. Esse monitoramento é feito para subsidiar ações de proteção e recuperação, visando garantir os usos atuais e futuros. Os dados provenientes do monitoramento são a base para a avaliação da qualidade das águas e para a produção de relatórios, diagnósticos e boletins sobre as condições dos corpos hídricos.

Com o intuito de colaborar na atenção dessa demanda ambiental, um grupo de pesquisadores da Universidade Federal Fluminense se destaca trazendo mais tecnologia para o processo de acompanhamento da qualidade dos recursos hídricos no estado do Rio de Janeiro. Alunos e docentes dos Departamentos de Engenharia Elétrica (TEE-UFF), Engenharia de Recursos Hídricos e Meio Ambiente (TGH-UFF), e do Instituto de Computação (IC-UFF), estão desenvolvendo em conjunto uma embarcação autônoma para monitoramento da água das baías e lagoas de Niterói. A iniciativa também tem apoio financeiro da Fundação Carlos Chagas Filho de Amparo à Pesquisa do Estado do Rio de Janeiro (FAPERJ) e conta com a parceria da Universidade Federal do Rio Grande do Norte (UFRN) e da empresa NVIDIA, líder mundial em soluções de Inteligência Artificial e sistemas computacionais de alto desempenho embarcado. 


![Screenshot](img/fboat.jpg)

## Arquitetura 
       # Arduino: Códigos e bibliotecas usadas para testes no arduino mega e uno. Os códigos carregados nos arduinos são: master_sailboat_RC_pixhawk no arduino mega e slave_vela_e_leme no arduino uno.
       # Códigos: Códigos dos arduinos usados antes de mudar o sistema para a pixhawk. Contém o firmware, os parâmetros e uma missão com pontos na logoa do bonfim.

    docs/
        index.md  # Arquivos do site de documentação do projeto.
        ...       # Other markdown pages, images and other files.

    Instalação o código fonte do firmware está em https://github.com/Natalnet/ardupilot.git, no branch nboat. Para compilar siga este tutorial de Setup On Ubuntu até o comando . ~/.profile. Se tudo der certo, use os comandos ./waf configure --board Pixhawk1 e ./waf rover. O firmware estará na pasta ardupilot/build/Pixhawk1/bin com o nome ardupilot.apj.
    
    Instale o MissionPlanner ou o QGroundControl para carregar o firmware na pixhawk. Após carregar o firmware, carregue na pixhawk os parâmetros do arquivo da pasta config_pixhawk/nboat_param.

## Comandos

* `mkdocs new [dir-name]` - Create a new project.
* `mkdocs serve` - Start the live-reloading docs server.
* `mkdocs build` - Build the documentation site.
* `mkdocs -h` - Print help message and exit.
