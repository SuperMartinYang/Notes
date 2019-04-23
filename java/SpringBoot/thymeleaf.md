# Thymeleaf

# config
* Maven
    * add repository

    ``` xml 
    <!-- Thymeleaf -->
    <dependency>
		<groupId>org.springframework.boot</groupId>
		<artifactId>spring-boot-starter-thymeleaf</artifactId>
	</dependency>
    <!-- dialect -->
    <dependency>
		<groupId>nz.net.ultraq.thymeleaf</groupId>
		<artifactId>thymeleaf-layout-dialect</artifactId>
		<version>2.0.5</version>
	</dependency>
    ```
* No need to config, just use layout
    ``` html 
    <!-- header.html -->
    <header th:fragment="header" xmlns:th="http://www.thymeleaf.org">
        ...
    </header>


    <!-- footer.html -->
    <div th:fragment="footer" class="footer" xmlns:th="http://www.thymeleaf.org">
        ...
    </div>


    <!-- main_shared.html -->
    <!DOCTYPE html>
    <html xmlns:th="http://www.thymeleaf.org" xmlns:layout="http://www.w3.org/1999/xhtml">
        <head>
            ...
        </head>
        <body>
            <!--header.html  that's here  -->
            <div th:replace="fragments/header :: header"></div>

            <div layout:fragment="content"></div>
            <!--footer.html  that's here  -->
            <div th:replace="fragments/footer :: footer"></div>
        </body>
    </html>

    <!-- Partial (real content) -->
    <!DOCTYPE html>
    <html layout:decorate="~{fragments/main_layout}" xmlns:layout="http://www.w3.org/1999/xhtml">
        <head>
            <title>Home</title>
        </head>
        <body id="index">
            <!-- /* Content of this page will be decorated by the elements of layout.html (task/layout) */ -->
            <div layout:fragment="content" id="main">
            ...
            </div>
        </body>
    </html>
    ```

