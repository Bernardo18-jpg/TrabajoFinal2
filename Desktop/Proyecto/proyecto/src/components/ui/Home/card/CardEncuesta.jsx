import React from "react";
import { Card, Text, Button, Row } from "@nextui-org/react";

const CardEncuesta = ({ titulo, descripcion, id }) => {
  return (
    <Card css={{ mw: "330px" }}>
      <Card.Header>
        <Text>{titulo}</Text>
      </Card.Header>
      <Card.Divider />
      <Card.Body css={{ py: "10" }}>
        <Text>{descripcion}</Text>
      </Card.Body>
      <Card.Divider />
      <Card.Footer>
        <Row justify="center">
          <Button size="sm">{`${id} - ver mas`}</Button>
        </Row>
      </Card.Footer>
    </Card>
  );
};

export default CardEncuesta;
