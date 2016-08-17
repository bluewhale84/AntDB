#include "postgres.h"

#include "access/heapam.h"
#include "access/htup_details.h"
#include "catalog/agtm_sequence.h"
#include "catalog/indexing.h"
#include "storage/lock.h"
#include "utils/builtins.h"
#include "utils/rel.h"

void AddAgtmSequence(const char* database,
				const char* schema, const char* sequence)
{
	Relation	adbSequence;
	HeapTuple	htup;
	Datum		values[Natts_agtm_sequence];
	bool		nulls[Natts_agtm_sequence];
	NameData    nameDatabase;
	NameData    nameSchema;
	NameData    nameSequence;
	
	MemSet(values, 0, sizeof(values));
	MemSet(nulls, false, sizeof(nulls));
	
	namestrcpy(&nameDatabase, database);
	values[Anum_agtm_sequence_database - 1] = NameGetDatum(&nameDatabase);

	namestrcpy(&nameSchema, schema);
	values[Anum_agtm_sequence_schema - 1] = NameGetDatum(&nameSchema);

	namestrcpy(&nameSequence, sequence);
	values[Anum_agtm_sequence_sequence - 1] = NameGetDatum(&nameSequence);

	adbSequence = heap_open(AgtmSequenceRelationId, RowExclusiveLock);
	htup = heap_form_tuple(RelationGetDescr(adbSequence), values, nulls);

	(void) simple_heap_insert(adbSequence, htup);

	/* add index */

	heap_close(adbSequence, RowExclusiveLock);	
}


