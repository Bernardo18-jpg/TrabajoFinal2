import { Card, Grid, Text, Button, Row, Container } from "@nextui-org/react";
import ButtonEncuesta from "../components/ui/Home/botonAgregarEncuesta/ButtonEncuesta";
import GridCardContainer from "../components/ui/Home/container/GridCardContainer";

const HomePage = () => {
  return (
    <div className="layout">
      <Container></Container>
      {/* Titulo */}
      <h1>Bienvenidos a la pagina principal de encuestas online</h1>
      <ButtonEncuesta></ButtonEncuesta>
      {/*boton agregar //container cards*/}
     <GridCardContainer></GridCardContainer>
    </div>
  );
};

export default HomePage;
